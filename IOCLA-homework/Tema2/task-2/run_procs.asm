%include "../include/io.mac"

    ;;
    ;;   TODO: Declare 'avg' struct to match its C counterpart
    ;;

struc proc
    .pid: resw 1
    .prio: resb 1
    .time: resw 1
endstruc
struc avg
    .quo:  resw 1
    .remain:  resw 1
endstruc


    ;; Hint: you can use these global arrays
section .data
    prio_result dd 0, 0, 0, 0, 0
    time_result dd 0, 0, 0, 0, 0

section .text
    global run_procs
    extern printf
    
run_procs:
    ;; DO NOT MODIFY

    push ebp
    mov ebp, esp
    pusha

    xor ecx, ecx

clean_results:
    mov dword [time_result + 4 * ecx], dword 0
    mov dword [prio_result + 4 * ecx],  0

    inc ecx
    cmp ecx, 5
    jne clean_results

    mov ecx, [ebp + 8]      ; processes
    mov ebx, [ebp + 12]     ; length
    mov eax, [ebp + 16]     ; proc_avg
    ;; DO NOT MODIFY

    ;; Your code starts here

    ;esi = i
    ;edi = prio

    xor esi, esi ;i = 0
    xor edi, edi 
    imul ebx, 5 

;for (i = 0 ;i < ebx; i++)
main_loop:
    cmp esi, ebx                                ;(cmp esi,ebx) a.k.a (cmp i, length)
    jge calculate_time                          ;if (i >= length) break

    movzx edi, byte[ecx + esi + proc.prio]    ;edi = v[i].prio

    push ebx
    push eax

    xor eax, eax

    mov ebx, [prio_result + 4 * edi - 4]      ;ebx = prio_result[prio-1]
    inc ebx                                     ;prio_result[prio-1]++
    mov ax, [ecx + esi + proc.time]             ;time_result[prio-1] += v[i].time

    mov [prio_result + 4 * edi - 4], ebx
    add [time_result + 4 * edi - 4], eax

    pop eax
    pop ebx

    add esi, 5                          ;i++
    jmp main_loop


calculate_time:
    xor esi, esi ;i = 0
    mov edi, eax

;edx = remain
;eax = quo
;edi = proc_avg
;ecx = div
time_result_loop:
    cmp esi, 20
    jge exit

    mov eax, [time_result + esi]        ;eax = time_result[i] -> quotinent
    xor edx, edx                        ;edx = 0 -> remain
    mov ecx, [prio_result + esi]        ;ecx = prio_result[i]

    cmp  ecx, 0                         ;verif if div != 0
    je jump

    div ecx                             ;dividing time with prio


    mov [edi + esi + avg.quo], ax
    mov [edi + esi + avg.remain], dx   

jump:
    add esi, 4
    jmp time_result_loop


exit:


    ;; Your code ends here
    
    ;; DO NOT MODIFY
    popa
    leave
    ret

    ;; DO NOT MODIFY