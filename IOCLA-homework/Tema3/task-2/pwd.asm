section .data
	back db "..", 0
	curr db ".", 0
	slash db "/", 0
	; declare global vars here
	extern strcmp
	extern strcat

section .text
	global pwd

;;	void pwd(char **directories, int n, char *output)
;	Adauga in parametrul output path-ul rezultat din
;	parcurgerea celor n foldere din directories
pwd:
	enter 0, 0
	pushad
	mov esi, [ebp + 8] ;array of the strings
	mov edi, [ebp + 12] ;numer n
	xor ebx, ebx
	xor eax, eax	;eax = 0

;we put only the directories on the stack
parkour_array:
	cmp ebx, edi
	jge end_parkour

;verif if the string is ".."
verif_back:
	push eax  	;push eax

	push dword[esi + 4*ebx]
	push back
	call strcmp
	add esp, 8
	
	cmp eax, 0
	jne verif_curr

	pop eax		;pop eax

	cmp eax, 0
	je verif_curr

	dec eax
	pop edx
	inc ebx
	jmp parkour_array

;verif if the sting is "."
verif_curr:

	pop eax		;pop eax
	push eax	;push eax-2

	push dword[esi + 4*ebx]
	push curr
	call strcmp
	add esp, 8


	cmp eax, 0
	jne is_word

	pop eax 	;pop eax-2

	inc ebx
	jmp parkour_array

;if the string is a directory
is_word:

	pop eax		;pop eax-2

	push dword[esi + 4*ebx]
	inc eax

	inc ebx
	jmp parkour_array

end_parkour:
	;find the pointer where it beggins to stack
	mov ebx, eax
	mov edx, esp
	imul eax, 4
	sub eax, 4
	add edx, eax
	mov eax, ebx

	mov ecx, [ebp + 16]		;ecx = array of output

	xor ebx, ebx
;put the strings in the array, backwards
insert_strings:
	cmp ebx, eax
	jge last_slash

	;put the "/" in output array
	push ecx
	push eax
	push edx

	push slash 
	push ecx
	call strcat
	add esp, 8

	pop edx
	pop eax
	pop ecx

	;put the string in output array
	push ecx
	push eax
	push edx

	;find the pos 
	mov esi, ebx
	imul ebx, 4
	sub edx, ebx
	mov ebx, esi

	push dword[edx]
	push ecx
	call strcat
	add esp, 8

	pop edx
	pop eax
	pop ecx

	inc ebx
	jmp insert_strings

last_slash:
	;put the a slash "/" at the end of word 

	push slash 
	push ecx
	call strcat
	add esp, 8

	;clean the stack
	add esp, eax
	lea esp, [ebp - 32]


exit:
	popad
	leave
	ret