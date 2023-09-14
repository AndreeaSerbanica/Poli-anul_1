section .data
	; declare global vars here

section .text
	global reverse_vowels

;;	void reverse_vowels(char *string)
;	Cauta toate vocalele din string-ul `string` si afiseaza-le
;	in ordine inversa. Consoanele raman nemodificate.
;	Modificare se va face in-place
reverse_vowels:

	push ebp
	push esp
	pop ebp

	;address of the string
	push dword[ebp + 8]
	pop eax

	push esi
	push edi
	push ebx

	
	;esi = eax ;stringul
	push eax
	pop esi

;find the vowels and put them on the stack
find_vowels:
	cmp byte[esi], 0
	je end_find

	;verif if the character is 'aeiou'
	cmp byte[esi], 'a'
	je push_on_stack

	cmp byte[esi], 'e'
	je push_on_stack

	cmp byte[esi], 'i'
	je push_on_stack

	cmp byte[esi], 'o'
	je push_on_stack

	cmp byte[esi], 'u'
	je push_on_stack

	inc esi
	jmp find_vowels

;push 2 bytes on the stack
push_on_stack:
	push word[esi]

	inc esi
	jmp find_vowels


;find the vowels again and pop the vowels from the stack
end_find:
	xor ecx, ecx

;parkour the array again and where we find a vowel we pop the character that 
find_vowels2:
	cmp byte[eax + ecx], 0
	je exit

	;verif if the character is 'aeiou'
	cmp byte[eax + ecx], 'a'
	je swap_vowels

	cmp byte[eax + ecx], 'e'
	je swap_vowels

	cmp byte[eax + ecx], 'i'
	je swap_vowels

	cmp byte[eax + ecx], 'o'
	je swap_vowels

	cmp byte[eax + ecx], 'u'
	je swap_vowels

	inc ecx
	jmp find_vowels2

;pop from stack and make bit operations
swap_vowels:
	pop dx
	and byte[eax + ecx], 0
	or byte[eax + ecx], dl

	inc ecx
	jmp find_vowels2

exit:


	pop ebx
	pop edi
	pop esi
	push ebp
	pop esp
	pop ebp
	ret