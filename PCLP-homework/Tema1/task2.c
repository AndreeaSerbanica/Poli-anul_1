#include <stdio.h>
#define LUNGIME 1001

int main() {
    int N = 0, i = 0, poz = -1, operatii[LUNGIME] = {0};
    float s = 0, numere[LUNGIME];
    char semne[LUNGIME];
    scanf("%d", &N);
    for ( i = 0; i < N; i++ ) {
        scanf("%f", &numere[i]);
    }
    for ( i = 0; i < N - 1; i++ ) {
        scanf(" %c", &semne[i]);
        if ( semne[i] == '*' || semne[i] == '/' ) {
            if ( poz == -1 ) {
            poz = i;
            }
            operatii[i] = 1;
        }
    }

    if ( N != 0 ) {
        s = numere[0];
    }

    if ( poz != -1 ) {
        for ( i = poz; i < N - 1; i++ ) {
            if ( operatii[i] == 1 ) {
                if ( semne[i] == '*' ) {
                    numere[i + 1] = numere[i] * numere[i + 1];
                    if (semne[i - 1] == '+') {
                        semne[i] = '+';
                    } else if ( semne[i - 1] == '-' ) {
                        semne[i] = '-';
                    }
                    numere[i] = 0;
                } else if ( semne[i] == '/' ) {
                    numere[i + 1] = numere[i] / numere[i + 1];
                    if (semne[i - 1] == '+') {
                        semne[i] = '+';
                    } else if ( semne[i - 1] == '-' ) {
                        semne[i] = '-';
                    }
                    numere[i] = 0;
            }
            }
        }
    }

    for ( i = 0; i < N; i++ ) {
         if ( semne[i] == '+' ) {
            s = s + numere[i + 1];
        } else if ( semne[i] == '-' ) {
            s = s - numere[i + 1];
        }
    }
    printf("%f\n", s);
    return 0;
}
