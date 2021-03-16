; exercitiul 10, prima parte - fara semn
bits 32 
global  start 

extern  exit 
import  exit msvcrt.dll
      
segment  data use32 class=data 
	a db 10
	b dw 2
	c dd 15
	d dq 10
segment  code use32 class=code 
start: 
	mov al, [a] ; mutam a in al
	mov ah, 0 ;conversie fara semn de la al la ax
    mov dx, 0 ;conversie fara semn de la ax la dx:ax
    
    push dx
	push ax
	pop eax ; eax = a
    mov edx, 0 ; conversie fara semn de la eax la edx:eax
    
    add eax, dword [d] ; CF = 1, in caz de overflow
    adc edx, dword [d + 4] ; se adauga si CF, edx:eax = a + d
    
    add eax, dword [d] ; CF = 1, in caz de overflow
    adc edx, dword [d + 4] ; se adauga si CF, edx:eax = a + d + d
    
    sub eax, dword [c] ; edx:eax = (a + d + d) - c
    
    mov bx, [b] ; il mutam pe b in bx
    add bx, [b] ; bx = b + b
    
    mov cx, 0 ; conversie fara semn de la bx la cx:bx
    
    push cx
    push bx
    pop ebx ; ebx = b + b
    
    add eax, ebx
	
	push dword 0 
	call [exit]	