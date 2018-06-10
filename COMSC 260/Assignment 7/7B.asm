TITLE Program Template (7B.asm)
; Program Description: A program finds the GCD of different integers input.
; Author: Richard Xie
; Creation Date: 11/13/2016

INCLUDE Irvine32.inc

.data
array SDWORD -100, -20, 2, 32, 44, 78, 98, 105, 120, 240
str1 byte "GCD is: ", 0

.code
main PROC
mov ecx, LENGTHOF array / 2
mov esi,OFFSET array

L1:
mov  edi, 2

L2:
mov eax, [esi]
add esi, 4
cmp eax, 0
jl L3
jmp L4

L3:
neg eax

L4:
push eax
dec edi
cmp edi, 0
jne L2
call gcd
mov edx, OFFSET str1
call writestring
call writedec
call crlf
loop L1
exit
main ENDP
 
;---------------------------------------------
gcd PROC
;---------------------------------------------
pop edi
pop eax
pop ebx

gcd1:
mov edx, 0
div ebx
mov eax, ebx
mov ebx, edx
cmp ebx, 0
jg gcd1
push edi
ret
gcd ENDP
 
END main