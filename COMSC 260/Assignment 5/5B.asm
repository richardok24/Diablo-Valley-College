TITLE Program Template (5B.asm)
; Program Description:
; Author: Richard Xie
; Creation Date: 10/09/2016

INCLUDE Irvine32.inc

.data

.code
main PROC
mov  ecx, 16
mov  ebx, 0

L1:
push ecx
mov ecx, 16

L2:
mov eax, ebx
call SetTextColor
mov al, 'A'
call WriteChar
inc ebx
loop L2

call crlf
pop ecx
loop L1

mov eax, 0 + 15 * 16
call SetTextColor
INVOKE ExitProcess, 0

main ENDP
END main