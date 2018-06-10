TITLE Program Template (7A.asm)
; Program Description: A program that performs simple encryption by rotating each plaintext byte a varying number of positions in different directions.
; Author: Richard Xie
; Creation Date: 11/13/2016

INCLUDE Irvine32.inc

.data
key BYTE -2, 4, 1, 0, -3, 5, 2, -4, -4, 6
keySize = $ - key
plainText BYTE "This is a secret message, which will be encrypted",0

.code
main PROC
call Clrscr
mov  edx,OFFSET plainText	; display the original text
call	WriteString
call CrLf
call CrLf
mov  esi,OFFSET plainText
	
L1:
mov  ecx,keySize
mov  edi,OFFSET key
call Encode					; encode 10 bytes
jnz	L1						; continue if ZF not set
mov  edx,OFFSET plainText	; display the encoded text
call	WriteString
call CrLf
call CrLf

mov  esi,OFFSET plainText
	
L2:
mov  ecx,keySize
mov  edi,OFFSET key
call Decode					; decode 10 bytes
jnz	L2						; continue if ZF not set

mov  edx,OFFSET plainText	; display the decoded text
call WriteString
call Crlf
call CrLf
exit
main ENDP

;-----------------------------------------------------
Encode PROC
;-----------------------------------------------------

L1:
push ecx					; save loop count
cmp  BYTE PTR[esi],0		; end of string?
je	L4						; yes: quit with ZF=1

mov	cl,[edi]				; key byte
cmp  cl,0					; if positive, skip to L2
jge  L2
rol  BYTE PTR[esi],cl		; else, rotate left
jmp	L3

L2:
ror	BYTE PTR[esi],cl		; rotate right

L3:
inc	esi						; next plaintext byte
inc	edi						; next key byte
pop	ecx						; restore loop count
loop L1
	
; Clear the zero flag to indicate that we have
; not yet reached the end of the string.
or	eax,1
jmp	L5

L4:	pop	ecx					; ecx was left on the stack

L5:	ret
Encode ENDP

;-----------------------------------------------------
Decode PROC
;-----------------------------------------------------

L1:
push ecx					; save loop count
cmp  BYTE PTR[esi],0		; end of string?
je	L4						; yes: quit with ZF=1

mov	cl,[edi]				; key byte
cmp  cl,0					; if positive, skip to L2
jge  L2
ror  BYTE PTR[esi],cl		; else, rotate right
jmp	L3

L2:
rol	BYTE PTR[esi],cl		; rotate left

L3:
inc	esi						; next plaintext byte
inc	edi						; next key byte
pop	ecx						; restore loop count
loop L1
	
; Clear the zero flag to indicate that we have
; not yet reached the end of the string.
or	eax,1
jmp	L5

L4:	pop	ecx					; ecx was left on the stack

L5:	ret
Decode ENDP

END main