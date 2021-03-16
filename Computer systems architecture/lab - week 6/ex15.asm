; our data is declared here (the variables needed by our program)
; Given the words A and B, compute the doubleword C as follows:
; the bits 0-2 of C have the value 0
; the bits 3-5 of C have the value 1
; the bits 6-9 of C are the same as the bits 11-14 of A
; the bits 10-15 of C are the same as the bits 1-6 of B
; the bits 16-31 of C have the value 1

bits 32 

global start        

extern exit               
import exit msvcrt.dll

segment data use32 class=data
    a dw 15
    b dw 2
    c dd 0

segment code use32 class=code
    start:
        xor ebx, ebx ; ebx = 0
        mov ebx, 11111111111111110000000000111000b  ; setam bitii de 1 si 0 care vor fi in c
        xor eax, eax ; eax = 0
        mov ax, [a] ; ax = a = 15
        mov cl, 5 ; cl = 5
        shr ax, cl ; bitii din ax = a se shifteaza la dreapta 5 pozitii, bitii din dreapta devin 0
        and ax, 0 00000 11110 00000b 
        cwde ; eax = ax
        add ebx, eax ; muta in ebx bitii care ne trebuiau din a
        xor eax, eax ; eax = 0
        mov ax, [b] ; ax = b
        mov cl, 9  ; cl = 9
        shl ax, cl ; muta bitii din b pe pozitiile pe care trebuie sa fie, umple restul din dreapta cu 0
        and ax, 1 11111 00000 00000b 
        
        cwde ; eax = ax (bitii din b)
        add ebx, eax ; adauga in ebx bitii din b
        mov [c], ebx ; c primeste valoarea ebx
        
        push    dword 0      
        call    [exit]      
