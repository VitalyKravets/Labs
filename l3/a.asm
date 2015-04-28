   global _f
_f:
        push    ebp
		shl 	eax, 2
		shr		edx, 2
		push 	eax
		push 	edx
		xor 	edx, edx
		mov 	eax, ecx
		mov 	ebx, 3
		idiv 	ebx
		mov 	ecx, edx
		pop 	edx
		pop     eax
		;mov 	eax, edx
		add		eax, ecx
		add 	eax, edx
		pop 	ebp    
  
        ret                  
