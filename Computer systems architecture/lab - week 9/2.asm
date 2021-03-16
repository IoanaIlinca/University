; eax = fread (*str, size, count, FILE)
; eax = fopen (*name, *mode)
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf, fread, fopen, fclose             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    n db "ana.txt", 0
    m db "r", 0
    d_f dd -1 ; = d_f resd -1
    c dd 0
    buff resb 100
    len equ $-buff

; our code starts here
segment code use32 class=code
    start:
        push m
        push n
        call [fopen]
        cmp eax, 0
        je .end
        mov [d_f], eax
        add esp, 4 * 2
        .r
        push dword [d_f]
        push len
        push 1
        push buff
        call [fread]
        cmp eax, len
        add esp, 4 * 4
        je .r
        
        push dword [d_f]
        call [fclose]
        add esp, 4 * 1
        
        
        .end
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
