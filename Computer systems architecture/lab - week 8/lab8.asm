bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    f db "Ana %s are %d mere", 0
    n db "Pop", 0

; our code starts here
segment code use32 class=code
    start:
        ; printf (const char* f, v1, v2, ...)
        push 7
        push n
        push f
        
        call [printf]
        add esp, 4*3
        ; scanf(f, v1, v2, ...)
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
