extern array_idx_1      ;; int array_idx_1

section .text
    global inorder_parc


;   struct node {
;       int value;
;       struct node *left;
;       struct node *right;
;   } __attribute__((packed));

;;  inorder_parc(struct node *node, int *array);
;       functia va parcurge in inordine arborele binar de cautare, salvand
;       valorile nodurilor in vectorul array.
;    @params:
;        node  -> nodul actual din arborele de cautare;
;        array -> adresa vectorului unde se vor salva valorile din noduri;

; ATENTIE: vectorul array este INDEXAT DE LA 0!
;          Cititi SI fisierul README.md din cadrul directorului pentru exemple,
;          explicatii mai detaliate!
; HINT: folositi variabila importata array_idx_1 pentru a retine pozitia
;       urmatorului element ce va fi salvat in vectorul array.
;       Este garantat ca aceasta variabila va fi setata pe 0 la fiecare
;       test.

inorder_parc:
    enter 0, 0
;     pushad

    
;     mov ebx, [ebp + 8] ;the root node
;     mov eax, [ebp + 12] ;the array


;     cmp ebx, 0 ;check if the root node is NULL
;     je exit

;     ;trasvers the tree in left-side
;     mov ebx, [ebx + 4] ;get the left child
;     push ebx
;     push eax
;     call inorder_parc
;     add esp, 8

;     mov ecx, [array_idx_1] ;array_idx_1

;     mov edx, [ebp + 8] ;the root node again
;     mov ebx, [edx] 
;     mov [eax + ecx * 4], ebx ;store the value in the array

;     inc dword[array_idx_1]

;     ;trasvers tree on the right side
;     mov ebx, [edx + 8] ;get the right child
;     push ebx
;     push eax
;     call inorder_parc
;     add esp, 8

; exit:

;     popad
    leave
    ret
