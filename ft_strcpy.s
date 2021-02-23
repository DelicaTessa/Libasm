; char *ft_strcpy(char *dst/rdi, const char *src/rsi)

section.text:
    global _ft_strcpy

_ft_strcpy:
    xor rax, rax             ; set rax to 0

_loop:
    mov dl, byte [rsi + rax] ; give dl the value of src
    mov byte [rdi + rax], dl ; give dst the value of src
    inc rax 				 ; increment index
    cmp byte [rsi + rax], 0  ; is it a null terminator?
    je _end				     ; if yes, proceed to end
    jne _loop				 ; if not, go through loop again

_end:
    mov dl, byte [rsi + rax] ; move null terminator in dl
    mov byte [rdi + rax], dl ; move null terminator in dest
    mov rax, rdi             ; move dest in rax cause rax is what gets returned
    ret						 ; return rax

