; exercitiul 10, prima parte - cu semn
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
	mov al, [a] ; al = a
    cbw ; AL devine AX, cu semn
    add ax, [b] ; ax = a + b
    cwde ; AX devine EAX, cu semn
    
    add eax, [c] ; dx:ax = a + b + c
    
    cdq ; EAX devine EDX:EAX
    
    add eax, dword [d] ; CF = 1, in caz de overflow
    adc edx, dword [d + 4] ; se adauga si CF, edx:eax = b + c + d + a
    
    sub eax, dword [d] ; CF = -1, in caz de overflow
    sbb edx, dword [d + 4] ; se adauga si CF, edx:eax = b + c + d + a - d
    
    sub eax, [c] ;edx:eax = b + c + d + a - (d + c)
    
    
    
	
	push dword 0 
	call [exit]	