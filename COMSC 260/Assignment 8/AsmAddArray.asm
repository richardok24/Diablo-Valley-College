TITLE Program Template (AsmAddArray.asm)
; Author: Richard Xie
; Creation Date: 11/13/2016

.586
.model flat,C

AsmAddArray PROTO, srchVal:DWORD, arrayPtr:PTR DWORD, arraySize:DWORD

.code
;-----------------------------------------------
AsmAddArray PROC USES edi, mval:DWORD, arrayPtr:PTR DWORD, arraySize:DWORD
;
; Adds each element of an array by mval.
;-----------------------------------------------

mov ebx,mval    			; additive
mov ecx,arraySize      		; number of items
mov edi,arrayPtr   			; pointer to array
 	
L1:	
mov	eax, ebx				; get additive
add	eax, DWORD PTR[edi]		; add by array val
mov	DWORD PTR[edi], eax		; store in the array
add	edi, TYPE DWORD
loop L1
ret   

AsmAddArray ENDP
END