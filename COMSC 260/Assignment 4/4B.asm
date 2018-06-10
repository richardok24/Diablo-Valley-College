TITLE Program Template (4B.asm)
; Program Description:
; Author: Richard Xie
; Creation Date: 10/02/2016

INCLUDE Irvine32.inc

.data
array  DWORD  1, 2, 3, 4

.code
main PROC
mov ecx, 2
mov esi, 3
mov edi, 0

L1:
mov eax, array[esi * TYPE array]
xchg eax, array[edi]
mov array[esi * LENGTHOF array], eax
mov edi, TYPE array
mov esi, 2
loop L1
call dumpregs

mov eax, array
mov ebx, array[4]
mov ecx, array[8]
mov edx, array[12]
call dumpregs

exit
main ENDP
END main