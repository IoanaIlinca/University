bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s db 5, 25, 55, 127
    len equ $-s
    d resb len
    
;we construct the d(estination) string such that d[i] is the number of 1 bits in the binary representation of s[i]
segment code use32 class=code
    start:
        mov esi, s
        mov edi, d
        mov ecx, len
        .repeta:
            lodsb;al<-s[i]
            push ecx ;number of repetitions left goes to stack
            mov ecx, 8
            mov bl, 0
            .repeta2:;we parse through the bits of al using cf 
                rcr al, 1
                adc bl, 0; we add cf to bl and we obtain in bl the number of 1  bits of al
                loop .repeta2        
            mov al,bl
            stosb; put al in the destination string
            pop ecx; ecx<-number of repetitions left
            loop .repeta
        ;result in destination string d
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
