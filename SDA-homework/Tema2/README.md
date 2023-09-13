/*
    SERBANICA Andreea-Maria - 313CD
*/

-In tema2.c se afla main-ul
-In Tree.c si Tree.h se afla functiile folosite la task1, ca sa formezi arborele si sa afli datele despre el(inaltimea, dimensiunea maxima, numarul de frunze)
-In Compression.c si Compression.h se afla functiile folosite la task2, pentru compresia arborelui
-In Decompression.c si Decompression.h se afla functiile folosite la task3, pentru crearea arborelui si a matricei
-In Queue.c si Queue.h se afla functiile specifice unei cozi.


TASK 1:
	Cream o matrice de tipul Pixel, in care punem culorile pixelilor(red, green, blue). Folosim functia 'divide_and_insert' ca sa divizam matricea recursiv in 4 parti. Ne folosim de 2 variabile: startRow si startCol, in care retinem pozitia fiecarui patrat in care divizam matricea. Astfel divizam intotdeauna patratele de la pozitiile: startRow, startCol; startRow, startCol + size; startRow + size, startCol + size; startRow + size,  startCol. Totodata, impartim size de fiecare data cand se reapeleaza functia. Astfel, in fiecare dintre cele 4 patrate calculam mean, iar daca mean <= factorul, bagam valoarea in arbore.
	Dupa ce cream arborele, aflam inaltimea, mergand pe fiecare nod: next1, next2, next3, next4 si aflam maximul dintre cele 4.
	Ca sa aflam numarul de noduri terminale, parcurgem arborele si crestem contorul de fiecare data cand intalnim un nod de tipul 1.
	Ca sa aflam dimensiunea cea mai mare din matrice, parcurg arborele pana cand gasesc primul nod terminal(leaf), si alfam returnam nivelul pe care se afla acesta. Dupa care calculam in functia 'calculateBiggestDimension' dimensiunea maxima.
	Dupa care le afisam pe toate.

TASK 2:
	Se creeaza arborele exact ca la taskul 1.
	Dupca ce se creeaza, parcurgem arborele pe nivel si scriem in fisierul binar culorile fiecarui pixel si tipul acestuia.
	
TASK 3:	
	Citim elementele din fisierul binar si le bagam intr-o coada. Pentru fiecare element din coada retinem tipul si culorile fiecarui pixel.
	Ca sa cream arborele, cream primul pixel si ii eliminam datele din coada. Apoi, cream arborele pe nivel si de fiecare cand inseram un nod, ii eliminam datele din coada. De asemena, de fiecare data cand ajungem pe nivelul care trebuie, verificam intai ce tip de nod e (1 sau 0). Daca este 1, dam return, iar daca este 0, cream alte 4 noduri.
	Ca sa cream matricea de pixeli, parcurgem arborele pana la NULL si de fiecare data cand intalnim un nod de tipul 1, bagam in matrice. Totodata, ca sa trecem in matrice, parcurgem recursiv matricea, impartind-o in cele 4 patrate, exact ca la task1. Se imparte de fiecare data size la 2, pana cand se intalneste un nod de tip 1.
	Dupa ce am creat matricea, folosim fwrite ca sa scriem elementele in fisierul binar.
