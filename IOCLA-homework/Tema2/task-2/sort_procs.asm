%include "../include/io.mac"

struc proc
    .pid: resw 1
    .prio: resb 1
    .time: resw 1
endstruc

section .text
    global sort_procs

sort_procs:
    ;; DO NOT MODIFY
    enter 0,0
    pusha

    mov edx, [ebp + 8]      ; processes
    mov eax, [ebp + 12]     ; length
    ;; DO NOT MODIFY

    ;; Your code starts here

    ;ebx = length-1, array values
    ;ecx = array values
    ;esi = i
    ;edi = j
    
    xor ecx, ecx
    imul eax, 5
;beggin of the for loops:

;for (i = 0; i < eax-1; i++)
    xor esi, esi        ;i = 0
outer_loop:
    mov ebx, eax        ;ebx = eax
    sub ebx, 5          ;ebx = eax-1
    cmp esi, ebx        ;i < length-1
    jge exit_loops

    mov edi, esi        ;j = i
    add edi, 5          ;j = i+1

;for ( j = i + 1 ; j < eax; j++)
inner_loop:
    cmp edi, eax    ;j < length
    jge exit_inner_loop

prio_compare:
    mov bl, [edx + esi + proc.prio]     ;v[i].prio
    mov cl, [edx + edi + proc.prio]     ;v[j].prio
    cmp cl, bl                          ;cmp v[j].prio, v[i].prio
    jl swap_var                         ;if (v[j].prio > v[i].prio)

    jg after_swap

time_compare:
    mov bx, [edx + esi + proc.time]     ;v[i].time
    mov cx, [edx + edi + proc.time]     ;v[j].time
    cmp cx, bx                          ;cmp v[j].time, v[i].time
    jl swap_var                         ;if (v[j].time < v[i].time)

    jg after_swap

pid_compare:
    mov bx, [edx + esi + proc.pid]     ;v[i].pid
    mov cx, [edx + edi + proc.pid]     ;v[j].pid
    cmp cx, bx                         ;cmp v[j].pid, v[i].pid

    jge after_swap

swap_var:
    mov bl, [edx + esi + proc.prio]    ;v[i].prio
    mov cl, [edx + edi + proc.prio]    ;v[j].prio
    mov [edx + esi + proc.prio], cl
    mov [edx + edi + proc.prio], bl

    mov bx, [edx + esi + proc.time]    ;v[i].time
    mov cx, [edx + edi + proc.time]    ;v[j].time
    mov [edx + esi + proc.time], cx
    mov [edx + edi + proc.time], bx

    mov bx, [edx + esi + proc.pid]     ;v[i].pid
    mov cx, [edx + edi + proc.pid]     ;v[j].pid
    mov [edx + esi + proc.pid], cx
    mov [edx + edi + proc.pid], bx

after_swap:
    add edi, 5                            ;j++
    jmp inner_loop
exit_inner_loop:
    add esi, 5                            ;i++
    jmp outer_loop

exit_loops:

    ;; Your code ends here
    
    ;; DO NOT MODIFY
    popa
    leave
    ret
    ;; DO NOT MODIFY