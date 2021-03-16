; exercitiul 10 - a doua parte - fara semn
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
    aux dd 2
	x dq 80
segment  code use32 class=code ; segmentul de cod
start:
    mov al, [a] ; mutam a in al
    mov ah, 0 ; conversie de la al la ax fara semn
    mul word [b] ; ax = a * b
    
    mov bl, 7 ; bl = 7
    add bl, [c] ; bl = 7 + c
    mov bh, 0 ; conversie de la bl la bx fara semn
    
    sub bx, ax ; bx = 7 - a * b + c
    mov ax, bx ; ax = 7 - a * b + c
    div byte [a]; al = (7 - a * b + c) / a, ah = (7 - a * b + c) % a
    
    add al, 6 ; al = (7 - a * b + c) / a + 6
    mov ah, 0 ; conversie fara semn de la al la ax
    mov bx, ax ; bx = (7 - a * b + c) / a + 6
    mov cx, 0 ; conversie fara semn de la bx la cx:bx
    
    push dword [d]
    pop eax ; eax = d
    
    push cx
    push bx
    pop ebx ; ebx  = (7 - a * b + c) / a + 6
    
    sub eax, ebx ; no overflow, because of the sizes of the operands in ebx, eax = d - (7 - a * b + c) / a - 6
    mov edx, 0 ; edx:eax = d - (7 - a * b + c) / a - 6
    
    mov ebx, eax 
	mov ecx, edx  ; ecx:ebx = d - (7 - a * b + c) / a - 6
    mov eax, dword [x]
    mov edx, dword [x + 4]
    div dword [aux] ; eax = x/2, edx = x % 2
    
    add eax, ebx ; eax = d - (7 - a * b + c) / a - 6 + x / 2
    
    
	
	push dword 0 ;se pune pe stiva codul de retur al functiei exit
	call [exit] ;apelul functiei sistem exit pentru terminarea executiei programului