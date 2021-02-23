; int     ft_strcmp(const char* s1/rdi, const char *s2/rsi);
section .text
	global _ft_strcmp

_ft_strcmp:			
	xor rax, rax				; i = 0;
_loop:
	mov cl, BYTE [rsi + rax]	; set s2[i] in cl
	cmp cl, BYTE [rdi + rax]	; compare cl with s1[i]
	ja _lower					; cl > s1[i]
	jb _greater					; cl < s1[i]
	cmp cl, 0					; check if \0 is found
	je _return					; if true, go to return
	inc rax						; if false, increment rax
	jmp _loop					; go through function again

_greater:
	mov rax, 1					; if rdi greater than rsi a positive number returns
	ret

_lower:
	mov rax, -1					; if rdi lesser then rsi a negative number returns
	ret

_return:
	mov rax, 0					; when equal a 0 is returned
	ret