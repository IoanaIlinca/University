bits 32

extern fopen
extern fclose

extern fprintf
extern exit

import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

global _hexafile

segment data public data use32
    printformat db '%x', 0
	file_name db "max.txt", 0   
	access_mode db "w", 0   
	file_descriptor dd -1 
	max dd 0

segment code public code use32

    _hexafile:

		push ebp
		mov ebp,esp
		mov ebx, [ebp+8]
		mov [max], ebx

        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4*2                

        mov [file_descriptor], eax  
		cmp eax, 0
        je final

        push dword[max]
        push printformat
		push dword [file_descriptor]
		call [fprintf]
        add esp, 4*3

		push dword [file_descriptor]
        call [fclose]
        add esp, 4

      final:
        mov esp,ebp
		pop ebp
		ret
        