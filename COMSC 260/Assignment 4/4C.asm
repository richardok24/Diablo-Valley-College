TITLE Program Template (4C.asm)
; Program Description:
; Author: Richard Xie
; Creation Date: 10/02/2016

INCLUDE Irvine32.inc

.data
val1 SDWORD 8
val2 SDWORD -15
val3 SDWORD 20

.code
main PROC
mov eax, val2      ;EAX = -15  FFFFFFF1h
neg eax            ;EAX = 15   0000000Fh
add eax, 7         ;EAX = 22   00000016h
sub eax, val3      ;EAX = 2    00000002h
add eax, val1      ;EAX = 10   0000000Ah
call DumpRegs

exit
main ENDP
END main