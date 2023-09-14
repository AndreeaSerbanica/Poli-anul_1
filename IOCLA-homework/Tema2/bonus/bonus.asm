section .data

section .text
    global bonus

bonus:
    ;; DO NOT MODIFY
    push ebp
    mov ebp, esp
    pusha

    mov eax, [ebp + 8]	; x
    mov ebx, [ebp + 12]	; y
    mov ecx, [ebp + 16] ; board

    ;; DO NOT MODIFY
    ;; FREESTYLE STARTS HERE

    mov edx, ecx

    xor edi, edi ;i = 0
    xor esi, esi ;j = 0

    mov edi, eax ;i = x
    mov esi, ebx ;j = y

left_up:
    dec edi         ;x-1
    dec esi         ;y-1

    cmp edi, 0
    jl right_up

    cmp esi, 0
    jl right_up

    ;calculate position
    mov ecx, edi
    imul ecx, 8
    add ecx, esi

    mov edi, 1
    shl edi, cl

    cmp ecx, 32
    jge second_number1

    or [edx + 4], edi

right_up:
    mov edi, eax
    mov esi, ebx

    dec edi         ;x-1
    inc esi         ;y+1

    cmp edi, 0
    jl left_down

    cmp esi, 7
    jg left_down

    ;calculate position
    mov ecx, edi
    imul ecx, 8
    add ecx, esi

    mov edi, 1
    shl edi, cl

    cmp ecx, 32
    jge second_number2

    or [edx + 4], edi

left_down:
    mov edi, eax
    mov esi, ebx

    inc edi         ;x+1
    dec esi         ;y-1

    cmp edi, 7
    jg right_down

    cmp esi, 0
    jl right_down

    ;calculate position
    mov ecx, edi
    imul ecx, 8
    add ecx, esi

    mov edi, 1
    shl edi, cl

    cmp ecx, 32
    jge second_number3

    or [edx + 4], edi

right_down:
    mov edi, eax
    mov esi, ebx

    inc edi         ;x+1
    inc esi         ;y+1

    cmp edi, 7
    jg exit

    cmp esi, 7
    jg exit

    ;calculate position
    mov ecx, edi
    imul ecx, 8
    add ecx, esi

    mov edi, 1
    shl edi, cl

    cmp ecx, 32
    jge second_number

    or [edx + 4], edi

    jmp exit


;go in the first part of the matrix
second_number1:
    or [edx], edi
    jmp right_up

second_number2:
    or [edx], edi
    jmp left_down

second_number3:
    or [edx], edi
    jmp right_down

second_number:
    or [edx], edi

exit:


    ;; FREESTYLE ENDS HERE
    ;; DO NOT MODIFY
    popa
    leave
    ret
    ;; DO NOT MODIFY