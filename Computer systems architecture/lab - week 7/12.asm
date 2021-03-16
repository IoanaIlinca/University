bits 32 

global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    s1 DB 'a', 'b', 'c', 'd', 'e', 'f' ; declararea stringului
    l1 equ (($ - s1) / 2 +  ($ - s1) % 2) ; lungimea stringului
    s2 DB '1', '2', '3', '4', '5'
    l2 equ ($ - s2) / 2
      
    d times (l1 + l2) db 0
    

segment code use32 class=code
    start:
        mov ecx, l2 ; pentru a face loopul
        mov esi, 1 ; index for source string
        mov edi, 0 ; index for destination string
        
        jecxz pas2 ; jump if condition is met la pas2
        Repeta1:
            mov al, [s2+esi] ; pozitiile pare din s2
            mov [d + edi], al 
            inc edi ; crestem indexul destinatiei
            inc esi 
            inc esi ; crestem cu 2 indexul sursei (indexarea din exemplu era de la 1)
        loop Repeta1    
        
        pas2: 
            mov ecx, l1
            mov esi, 0
            jecxz Sfarsit ; jump if condition is met la Sfarsit
            Repeta2:
                mov al, [s1 + esi] ; pozitiile impare din s1
                mov [d + edi], al 
                inc edi
                inc esi
                inc esi
            loop Repeta2
        
        Sfarsit:
        push    dword 0      
        call    [exit] 
