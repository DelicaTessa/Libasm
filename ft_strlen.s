; size_t ft_strlen(const char *s/rdi)

section.text:
    global _ft_strlen

_ft_strlen:
    xor rax, rax                 ; set rax to 0 by using xor (like doing i = 0)

_loop:
    mov dl, byte [rdi+rax]      ; give dl the value of the index
    cmp dl, 0x0                 ; check for null-terminator
    je _end                     ; if null-terminator is found then jump to end
    inc rax                     ; if null-terminator is not found increment the index
    jmp _loop                   ; go through the function again

_end:
    ret                         ; return rax