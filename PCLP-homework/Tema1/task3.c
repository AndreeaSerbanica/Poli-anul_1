
#include <stdio.h>
#define LUNGIME 1001

int main() {
    int N = 0, i = 0, poz = -1, contor = 0, vhastag = 0;
    float s = 0, numere[LUNGIME], numere2[LUNGIME];
    char semne[LUNGIME], semne2[LUNGIME];
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
        }
        if ( semne[i] == '#' ) {
            vhastag = 1;
        }
    }



    // facem operatiile cu '*' si '/':
    if ( poz != -1 ) {
        for ( i = poz; i < N - 1; i++ ) {
                if ( semne[i] == '*' ) {
                    numere[i + 1] = numere[i] * numere[i + 1];
                    numere[i] = 0;
                } else if ( semne[i] == '/' ) {
                    numere[i + 1] = numere[i] / numere[i + 1];
                    numere[i] = 0;
            }
        }
    }
    // eliminam toate 0 - urile din vector si bagam in altul
    if ( poz != -1 ) {
    for ( i = 0; i < N; i++ ) {
       if ( numere[i] != 0 ) {
        numere2[contor] = numere[i];
        if ( contor < N - 1 ) {
            semne2[contor] = semne[i];
        }
        contor++;
       }
    }

    for ( i = 0; i < contor; i++ ) {
        if ( numere2[i] != 0 ) {
            numere[i] = numere2[i];
            semne[i] = semne2[i];
        }
    }
    N = contor;
    }
    // trecem prin noul vector

    if ( vhastag == 1 ) {
        contor = 0;
        for ( i = 0; i < N; i++ ) {
            if ( semne[i] == '#' ) {
                numere[i + 1] = (numere[i] + numere[i + 1]) * (numere[i] + numere[i + 1]);
                    numere[i] = 0;
            }
        }

    for ( i = 0; i < N; i++ ) {
       if ( numere[i] != 0 ) {
        numere2[contor] = numere[i];
        if ( contor < N - 1 ) {
            semne2[contor] = semne[i];
        }
        contor++;
       }
    }

    for ( i = 0; i < contor; i++ ) {
        if ( numere2[i] != 0 ) {
            numere[i] = numere2[i];
            semne[i] = semne2[i];
        }
    }
    N = contor;
    }

    if ( N != 0 ) {
        s = numere[0];
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
