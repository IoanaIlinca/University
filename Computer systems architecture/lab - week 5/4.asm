; exercitiul 10 - a doua parte - cu semn
; d - (7 - a * b + c)/ a - 6 + x/2 ; a, c - byte; b - word; d - doubleword; x - qword
bits 32 
global  start 

extern  exit
import  exit msvcrt.dll
segment  data use32 class=data 
	a db 1
	b dw 8
	c db 10
	d dd 200
    aux dw 0
    aux2 dd 2
	x dq 80
segment  code use32 class=code 
start:
    mov al, [a] ; mutam a in al
    cbw ; conversie de la al la ax cu semn
    imul word [b] ; dx:ax = a * b
    mov cx, dx
    mov bx, ax ;cx:bx = a * b
    
    mov al, [c] ; al = c
    cbw ; al -> ax cu semn
    adc ax, 7 ; aduna cf in ax, ax = 7 + c
    cwd ; ax devine dx:ax = 7 + c
    
    sub ax, bx
    sbb dx, cx ; dx:ax = 7 - a * b + c 
    mov cx, dx
    mov bx, ax ; cx:bx = 7 - a * b + c 
    mov al, [a]
    cbw ; ax = a
    mov [aux], ax; aux = a
    
    
    mov ax, bx
    mov dx, cx ; dx:ax = 7 - a * b + c 
    idiv word [aux] ; AX ← DX:AX / aux, DX ← DX:AX % aux
                ; ax = (7 - a * b + c) / a
                
    mov ebx, [d]
    sbb ebx, 6 ; ebx = d - 6
    
    cwde ; ax devine eax = (7 - a * b + c) / a
    
    sub ebx, eax ; ebx = d - (7 - a * b + c) / a - 6
    sbb ebx, 0 ; ebx = d - (7 - a * b + c) / a - 6 + CF
    
    mov eax, dword [x]
    mov edx, dword [x + 4]  ; edx:eax = x
    idiv dword [aux2] ; eax = x / 2, edx = x % 2
    
    adc eax, ebx ; eax = d - (7 - a * b + c) / a - 6 + x / 2
    
	
	push dword 0 ;se pune pe stiva codul de retur al functiei exit
	call [exit] ;apelul functiei sistem exit pentru terminarea executiei programului