; char    *ft_strdup(const char *s1/rdi);

section.text:
    global _ft_strdup
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy

_ft_strdup:
    xor rax, rax           ; set rax to 0
    call _ft_strlen        ; strlen to calculate what needs to be mallocced, return value in rax
    push rdi               ; push rdi into stack to save it for later
    inc rax                ; increment rax for the null terminator
    mov rdi, rax           ; move rax into rdi to have malloc parameter
    push rbp               ; push base of stackframe to save it 
	mov rbp, rsp           ; move stackpointer into base of stackframe
	and rsp, - 16 		   ; force align stack
	call _malloc 		   ; call malloc to malloc memory for string
	mov rsp, rbp           ; stack pointer points to base of stackframe again
	pop rbp                ; restore the base of stackframe to its original value
    cmp rax, 0             ; check if malloc failed
    je _error;             ; if true, jump to error function
    mov rdi, rax           ; if false, move the mallocced string into rdi
    pop rsi                ; put the saved rdi-string in rsi
    push rbp               ; push base of stackframe to save it again
    mov rbp, rsp           ; move stackpointer into base of stackframe
    and rsp, - 16          ; force align stack
    call _ft_strcpy        ; now the rdi- and rsi-parameters for ft_strcpy are filled we can call it
    mov  rsp, rbp          ; stack pointer points to base of stackframe again
    pop rbp                ; restore the base of stackframe to its original value
    ret                    ; return the new string

_error:
    mov rax, 0             ; set rax to NULL
    ret                    ; return NULL