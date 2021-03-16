bits 32

global start
;ex28 from text file operations

; declare external functions needed by our program
extern exit, fopen, scanf, fclose,fprintf,printf
import printf msvcrt.dll
import exit msvcrt.dll
import fopen msvcrt.dll
import scanf msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    file_name db "outputFile.txt", 0   ; filename to be read
    access_mode db "w", 0       ; file access mode:
                                
    file_descriptor dd -1       ; variable to hold the file descriptor
    A resb 100
    format db '%s',0
    Outformat db '%s ',0
    message db 'Introduce word:',0
    letter resb 1
    ok db 0
; our code starts here
segment code use32 class=code
    start:
        ; call fopen() to create the file
        ; fopen() will return a file descriptor in the EAX or 0 in case of error
        ; eax = fopen(file_name, access_mode)
        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4 * 2                ; clean-up the stack

        mov [file_descriptor], eax  ; store the file descriptor returned by fopen

        ; check if fopen() has successfully created the file (EAX != 0)
        cmp eax, 0
        je .end
        .read:
        push dword message
        call [printf]
        add esp, 4 * 1
        push dword A       ; adress of A
        push dword format
        call [scanf]       ; call function scanf for reading
        add esp, 4 * 2
        
        mov ecx, 0
        mov byte [ok], 0 ; ok becomes 1 if the word contains a lowercaseletter
        .loop:
            
            mov al, [A + ecx]
            cmp al, 0
            je .endloop
            cmp al, '$' ;we read a $ character so we stop reading
            je .end
            cmp al, 'a'
            jb .skip ;al < 'a'
            cmp al,'z'
            ja .skip ; al > 'z'
            mov byte[ok], 1
            .skip:
            inc ecx
            jmp .loop
        
        .endloop:
        cmp byte[ok], 0
        je .read
        push dword A
        push Outformat
        push dword [file_descriptor]
        call [fprintf]
        add esp, 4 * 3
        jmp .read
        
        .end:
        
        ; call fclose() to close the file
        ; fclose(file_descriptor)
        push dword [file_descriptor]
        call [fclose]
        add esp, 4
        ; exit(0)
        push dword 0
        call [exit]