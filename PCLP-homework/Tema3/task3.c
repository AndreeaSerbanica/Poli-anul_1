#include <stdio.h>
#define BIT31 31
#define BIT30 30
#define BIT29 29
#define BIT28 28
#define LUNGIME 1001
#define NR_BITI_UNSIGNED_SHORT 16

int main() {
    unsigned int number = 0, N = 0, Op = 0, Dim = 0, cate_numere = 0;
    unsigned short numere_introduse[LUNGIME] = {0}, operanzi[LUNGIME] = {0}, semne[LUNGIME] = {0};
    int i = 0;
    scanf("%u", &number);
    N = (number >> BIT29) + 1;
    number = number << 3;
    int contor = 0;
    for ( i = 0; i < N; i++ ) {
        Op = number >> BIT30;
        if (Op == 0) {
            semne[contor] = 0;
            contor++;
        } else if (Op == 1) {
            semne[contor] = 1;
            contor++;
        } else if (Op == 2) {
            semne[contor] = 2;
            contor++;
        } else if (Op == 3) {
            semne[contor] = 3;
            contor++;
        }
        number = number << 2;
    }
    Dim = (number >> BIT28) + 1;
    if ( ((N + 1) * Dim) % NR_BITI_UNSIGNED_SHORT == 0 ) {
        cate_numere = ((N + 1) * Dim) / NR_BITI_UNSIGNED_SHORT;
    } else {
        cate_numere = ((N + 1) * Dim) / NR_BITI_UNSIGNED_SHORT + 1;
    }
    for ( i = 0; i < cate_numere; i++ ) {
        scanf("%hu", &numere_introduse[i]);
    }


    unsigned int k = 0, biti_fata = 0, biti_spate = NR_BITI_UNSIGNED_SHORT;
    unsigned short new_operand = 0, another_operand = 0;

    if (NR_BITI_UNSIGNED_SHORT % Dim == 0) {
        k = 0;
        for ( i = 0; i < cate_numere; i++ ) {
            biti_spate = NR_BITI_UNSIGNED_SHORT;
            for ( biti_fata = 0; biti_fata <= NR_BITI_UNSIGNED_SHORT - Dim; biti_fata += Dim ) {
                biti_spate = biti_spate - Dim;
                new_operand = numere_introduse[i];
                new_operand = new_operand << biti_fata;
                new_operand = new_operand >> (biti_fata + biti_spate);
                operanzi[k] = new_operand;
                k++;
            }
        }
    } else {
        k = 0;
        unsigned int dimeniune_maxima = 0, nr_biti_ramasi = 0, biti_de_completat = 0, nr_biti_principali = 0;
        for ( i = 0; i < cate_numere; i++ ) {
            nr_biti_principali = NR_BITI_UNSIGNED_SHORT - biti_de_completat;
            if (biti_de_completat != 0) {
                another_operand = another_operand + (numere_introduse[i] >> nr_biti_principali);
                operanzi[k] = another_operand;
                k++;
                if (k == N + 1) {
                    break;
                }
            }
            dimeniune_maxima = nr_biti_principali - (nr_biti_principali % Dim);
            if (dimeniune_maxima > 0) {
                biti_spate = dimeniune_maxima + (nr_biti_principali % Dim);
                for ( biti_fata = biti_de_completat; biti_fata <= dimeniune_maxima - Dim; biti_fata += Dim ) {
                    biti_spate = (biti_spate - Dim);
                    new_operand = numere_introduse[i];
                    new_operand = new_operand << biti_fata;
                    new_operand = new_operand >> (biti_fata + biti_spate);
                    operanzi[k] = new_operand;
                    k++;
                    if (k == N + 1) {
                        break;
                    }
                }
            }
            nr_biti_ramasi = nr_biti_principali % Dim;
            biti_de_completat = Dim - nr_biti_ramasi;
            another_operand = numere_introduse[i] << (NR_BITI_UNSIGNED_SHORT - nr_biti_ramasi);
            another_operand = another_operand >> (NR_BITI_UNSIGNED_SHORT - nr_biti_ramasi);
            another_operand = another_operand << biti_de_completat;
        }
    }

    int suma = operanzi[0];
    for ( i = 0; i < N; i++ ) {
        if (semne[i] == 0) {
            suma = suma + operanzi[i + 1];
        } else if (semne[i] == 1) {
            suma = suma - operanzi[i + 1];
        } else if (semne[i] == 2) {
            suma = suma * operanzi[i + 1];
        } else if (semne[i] == 3) {
            suma = suma / operanzi[i + 1];
        }
    }
    printf("%d\n", suma);
    return 0;
}
