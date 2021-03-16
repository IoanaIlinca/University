bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    n resd 1
    f db "%d", 0

; our code starts here
segment code use32 class=code
    start:
        ; scanf(f, v1, v2, ...)
        push n
        push f
        call [scanf]
        add esp, 4*3
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
