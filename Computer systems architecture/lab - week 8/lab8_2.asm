bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    d_f dd -1
    n db "ana.txt", 0
    m db "w", 0
    f db "ana are %d mere", 0

; our code starts here
segment code use32 class=code
    start:
        push m
        push n
        call [fopen]
        cmp eax, 0
        je endl
        
        mov [d_f], eax
        ; fprintf (FILE, f, v1, v2,...)
        push 2
        push f
        push dword [d_f]
        call [fprintf]
        add esi, 4*3
        
        
        endl:
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
