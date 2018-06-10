TITLE Program Template (5A.asm)
; Program Description:
; Author: Richard Xie
; Creation Date: 10/09/2016

INCLUDE Irvine32.inc

.data

.code
main PROC
call Clrscr
mov  ecx, 100

L1:	
call RandomLocation
mov  eax, 100
call Delay
loop L1
exit
main ENDP

RandomLocation PROC
call GetMaxXY

mov eax, 50
call RandomRange
mov dh, al

mov eax, 50
call RandomRange
mov dl, al

call Gotoxy
mov al, 'P'
call WriteChar
ret
RandomLocation ENDP

END main