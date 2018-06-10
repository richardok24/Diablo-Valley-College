TITLE Program Template (BooleanCalculator.asm)
; Program Description: Create a program that functions as a simple Boolean calculator for 32 bit integers.
; Author: Richard Xie
; Creation Date: 10/30/2016

INCLUDE Irvine32.inc

.data
msgMenu BYTE "---------- Boolean Calculator ----------",0dh,0ah
BYTE 0dh,0ah
BYTE "1. x AND y",0dh,0ah
BYTE "2. x OR y",0dh,0ah
BYTE "3. NOT x",0dh,0ah
BYTE "4. x XOR y",0dh,0ah
BYTE "5. Exit the program",0

msgAND BYTE "AND operation:",0
msgOR  BYTE "OR operation:",0
msgNOT BYTE "NOT operation:",0
msgXOR BYTE "XOR operation:",0

input1 BYTE "Enter the first 32-bit hexadecimal integer:  ",0
input2 BYTE "Enter the second 32-bit hexadecimal integer: ",0
result BYTE "Rresult: ",0

caseTable BYTE '1'	; lookup value
DWORD AND_operation	    ; address of procedure
EntrySize = ($ - caseTable)
BYTE '2'
DWORD OR_operation
BYTE '3'
DWORD NOT_operation
BYTE '4'
DWORD XOR_operation
BYTE '5'
DWORD ExitProgram
NumberOfEntries = ($ - caseTable) / EntrySize

.code
main PROC
call Clrscr

Menu:
mov edx, OFFSET msgMenu	; menu choices
call WriteString
call Crlf

L1:	call ReadChar
cmp al, '5'  ; is selection valid (1-5)?
ja L1	     ; if above 5, go back
cmp al, '1'
jb L1	     ; if below 1, go back

call Crlf
call ChooseProcedure
jc quit	     ; exit if CF = 1

call Crlf
jmp Menu	 ; display menu again

quit: exit
main ENDP

;------------------------------------------------
ChooseProcedure PROC
;------------------------------------------------
push ebx
push ecx

mov ebx, OFFSET caseTable    ; pointer to the table
mov ecx, NumberOfEntries     ; loop counter

L1:	cmp al, [ebx]	         ; match found?
	jne L2	; no: continue
	call NEAR PTR [ebx + 1]	 ; yes: call the procedure
	jmp L3

L2:	add ebx, EntrySize	     ; point to the next entry
	loop L1	                 ; repeat until ECX = 0

L3:	pop ecx
	pop ebx

ret
ChooseProcedure ENDP

;------------------------------------------------
AND_operation PROC
;------------------------------------------------
pushad
mov edx, OFFSET msgAND
call WriteString
call Crlf
call Crlf

mov edx, OFFSET input1	; first input
call WriteString
call ReadHex	        ; reads the first 32-bit hexadecimal integer
mov ebx, eax	        ; move it to EBX

mov edx, OFFSET input2	; second input
call WriteString
call ReadHex	        ; reads the second 32-bit hexadecimal integer

and eax, ebx	        ; AND operation

mov edx, OFFSET result	; result
call WriteString
call WriteHex
call Crlf
popad

ret
AND_operation ENDP

;------------------------------------------------
OR_operation PROC
;------------------------------------------------
pushad
mov edx, OFFSET msgOR
call WriteString
call Crlf
call Crlf

mov edx, OFFSET input1	; first input
call WriteString
call ReadHex	        ; reads the first 32-bit hexadecimal integer
mov ebx, eax	        ; move it to EBX

mov edx, OFFSET input2	; second input
call WriteString
call ReadHex	        ; reads the second 32-bit hexadecimal integer

or eax, ebx	            ; OR operation

mov edx, OFFSET result	; result
call WriteString
call WriteHex	        
call Crlf
popad	

ret
OR_operation ENDP

;------------------------------------------------
NOT_operation PROC
;------------------------------------------------
pushad
mov edx, OFFSET msgNOT
call WriteString
call Crlf
call Crlf

mov edx, OFFSET input1	; input
call WriteString
call ReadHex	        ; reads a 32-bit hexadecimal integer

not eax	                ; NOT operation

mov edx, OFFSET result	; result
call WriteString
call WriteHex
call Crlf
popad

ret
NOT_operation ENDP

;------------------------------------------------
XOR_operation PROC
;------------------------------------------------
pushad
mov edx, OFFSET msgXOR
call WriteString
call Crlf
call Crlf

mov edx, OFFSET input1	; first input
call WriteString
call ReadHex	        ; reads the first 32-bit hexadecimal integer
mov ebx, eax	        ; move it to EBX

mov edx, OFFSET input2	; second input
call WriteString
call ReadHex	        ; reads the second 32-bit hexadecimal integer

xor eax, ebx	        ; XOR operation

mov edx, OFFSET result	; result
call WriteString
call WriteHex
call Crlf
popad

ret
XOR_operation ENDP

;------------------------------------------------
ExitProgram PROC
;------------------------------------------------
stc
ret
ExitProgram ENDP

END main