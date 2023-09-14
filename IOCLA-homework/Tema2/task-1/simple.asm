%include "../include/io.mac"

section .text
    global simple
    extern printf

simple:
    ;; DO NOT MODIFY
    push    ebp
    mov     ebp, esp
    pusha

    mov     ecx, [ebp + 8]  ; len
    mov     esi, [ebp + 12] ; plain
    mov     edi, [ebp + 16] ; enc_string
    mov     edx, [ebp + 20] ; step

    ;; DO NOT MODIFY
   
    ;; Your code starts here

    xor ebx, ebx                ;initializam contorul ebx la 0
while_loop:
    cmp ebx, ecx                ;comparam ebx cu ecx
    jge exit_loop               ;iesim din bucla while daca ebx >= ecx
    mov al, byte [esi + ebx]    ;al = caractreului de pe pozitia lui ebx

    add al, dl                  ;adunam pasul de criptare
    cmp al, 'Z'                 ;verificam daca caracterul criptat depaseste valoarea lui Z
    jle no_wrap ;
    sub al, 26
no_wrap:
    mov byte [edi + ebx], al    ;punem byte ul in enc_string
    inc ebx
    jmp while_loop
    
exit_loop:


    ;; Your code ends here
    
    ;; DO NOT MODIFY

    popa
    leave
    ret
    
    ;; DO NOT MODIFY
