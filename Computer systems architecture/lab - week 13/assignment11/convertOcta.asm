bits 32

global convertOcta

segment data use 32 class=data
	c8 dw 8
	c10 dw 10

segment code use32 class=code
	convertOcta:
		mov ax, bx
		push ebx
		mov bx, 0
		mov dx, 0
		.getDigit:
		div word[c8]
		push edx
		cwd
		inc bx
		cmp ax, 0
		jne .getDigit
		mov ax, 0

		.computeOcta:
		mul word[c10]
		pop edx
		add ax,dx
		dec bx
		cmp bx,0
		jne .computeOcta
		pop ebx
		ret