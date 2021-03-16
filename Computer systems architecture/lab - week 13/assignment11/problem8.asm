; The program will use:
; - the function fopen() to open/create the file
; - the function fread() to read from file
; - the function fclose() to close the created file.

; Because the fopen() call uses the file access mode "r", the file will be open for
; reading. The file must exist, otherwise the fopen() call will fail.
; For details about the file access modes see the section "Theory".

bits 32

global start

; declare external functions needed by our program
extern exit, printf, fopen, fclose, fprintf, convertOcta
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "problem8Output.txt", 0   ; filename to be read
    access_mode db "w", 0       
    file_descriptor resd 1
	c8 dw 8
	c10 dw 10
    format db 'Number = %d Base8 = %d ASCII = %c',0xa,0
; our code starts here
segment code use32 class=code
    start:
        ; call fopen() to create the file
        ; fopen() will return a file descriptor in the EAX or 0 in case of error
        ; eax = fopen(file_name, access_mode)
        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4*2                ; clean-up the stack

        mov [file_descriptor], eax  ; store the file descriptor returned by fopen

        ; check if fopen() has successfully created the file (EAX != 0)
        cmp eax, 0
        je final
        mov ebx,32
		
		.write:
		mov eax,0
		call convertOcta
		
		
		push ebx
		push eax
		push ebx
		push format
		push dword[file_descriptor]
		call [fprintf]
		add esp,4*5
		
		inc bx	
		cmp bx,126
		jne .write
        
        

      final:
        ; call fclose() to close the file
        ; fclose(file_descriptor)
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        ; exit(0)
        push dword 0
        call [exit]