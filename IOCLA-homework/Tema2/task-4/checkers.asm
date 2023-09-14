
section .data

section .text
	global checkers

checkers:
    ;; DO NOT MODIFY
    push ebp
    mov ebp, esp
    pusha

    mov eax, [ebp + 8]	; x
    mov ebx, [ebp + 12]	; y
    mov ecx, [ebp + 16] ; table

    ;; DO NOT MODIFY
    ;; FREESTYLE STARTS HERE

    xor edi, edi
    xor esi, esi

    mov edi, eax
    mov esi, ebx

;edi = line
;esi = col

left_up:
    dec edi         ;x-1
    dec esi         ;y-1

    cmp edi, 0
    jl right_up

    cmp esi, 0
    jl right_up

;calculate position and put 1
    imul edi, 8
    mov edx, ecx
    add edx, edi
    add edx, esi
    mov byte[edx], 1

right_up:
    mov edi, eax
    mov esi, ebx

    dec edi         ;x-1
    inc esi         ;y+1

    cmp edi, 0
    jl left_down

    cmp esi, 7
    jg left_down

;calculate position and put 1
    imul edi, 8
    mov edx, ecx
    add edx, edi
    add edx, esi
    mov byte[edx], 1

left_down:
    mov edi, eax
    mov esi, ebx

    inc edi         ;x+1
    dec esi         ;y-1

    cmp edi, 7
    jg right_down

    cmp esi, 0
    jl right_down

;calculate position and put 1
    imul edi, 8
    mov edx, ecx
    add edx, edi
    add edx, esi
    mov byte[edx], 1

right_down:
    mov edi, eax
    mov esi, ebx

    inc edi         ;x+1
    inc esi         ;y+1

    cmp edi, 7
    jg exit

    cmp esi, 7
    jg exit

;calculate position and put 1
    imul edi, 8
    mov edx, ecx
    add edx, edi
    add edx, esi
    mov byte[edx], 1


exit:

    ;; FREESTYLE ENDS HERE
    ;; DO NOT MODIFY
    popa
    leave
    ret
    ;; DO NOT MODIFY