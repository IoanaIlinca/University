bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    output1 db "%d * %d = %d", 0
    output2 db "%d*%d=%d%d", 0
    a resd 1
    b resd 1
    format db '%d', 0
    messageB db 'B = ', 0
    messageA db 'A = ', 0

; our code starts here
segment code use32 class=code
    start:
        push dword messageA
        call [printf]
        add esp, 4 * 1
        push dword a       ; ! address of n, not value
        push dword format
        call [scanf]
        add esp, 4 * 2
        
        push dword messageB
        call [printf]
        add esp, 4 * 1
        push dword b       ; ! address of n, not value
        push dword format
        call [scanf]       ; call function scanf for reading
        add esp, 4 * 2     ; free parameters on the stack
                           ; 4 = size of a dword; 2 = no of perameters
                           
        mov eax, [a]
        imul dword [b]
        push dword eax
        cmp edx, 0          ;id edx=0 we jump to skip and not add edx to 
                           ; stack because that would end in printing a 0 in front of the product(stored completely in eax)
        
        je .skip
        push dword edx
        push dword [b]
        push dword [a]
        push dword output2 ; ! on the stack is placed the address of the string, not its value
        call [printf]      ; call function printf for printing 
        add esp, 4 * 5
        jmp .end
        
        .skip
        push dword [b]
        push dword [a]
        push dword output1
        call [printf]
        add esp, 4 * 4
        
        .end     
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
