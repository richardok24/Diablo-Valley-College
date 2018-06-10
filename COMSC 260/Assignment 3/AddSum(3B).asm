TITLE Program Template (Template.asm)
; Program Description: This program adds up four 32-bit integers
; Author: Richard Xie
; Creation Date: 09/11/16

INCLUDE Irvine32.inc
.data
val1	DWORD  10000h
val2	DWORD  20000h
val3	DWORD  30000h
val4	DWORD  40000h
result  DWORD  ?
.code
main PROC
mov		eax,val1		; start with 10000h
add		eax,val2		; add 20000h
add		eax,val3		; add 30000h
add		eax,val4		; add 40000h
mov		result,eax		; store the result (A0000h)
call	DumpRegs		; display the registers
exit
main ENDP
END main