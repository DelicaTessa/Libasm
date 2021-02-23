; ssize_t   ft_write(int fildes/rdi, const void *buf/rsi, size_t nbyte/rdx)

section.text:
    global _ft_write
    extern ___error

_ft_write:
    mov rax, 0x2000004 ; put call for write in rax (0x200000 for BSD-layer)
    syscall            ; system call for write
    jc _handle_error   ; if CF is set, go to handle_error
    ret                ; if CF is not set, return rax

_handle_error:
    mov rdi, rax       ; save errno code in rdi
    push rbp           ; push base of stackframe to save it 
    mov rbp, rsp       ; move stackpointer into base of stackframe
    and rsp, - 16      ; force align stack
    call ___error      ; call errno function, function returns an int * in rax
    mov rsp, rbp       ; stack pointer points to base of stackframe again
    pop rbp            ; restore the base of stackframe to its original value
    mov [rax], rdi     ; move the errno code that I saved into rax to set errno
    mov rax, -1        ; write should return -1 if it has an error
    ret                ; return rax