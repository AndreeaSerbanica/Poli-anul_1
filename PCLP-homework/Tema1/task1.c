#include <stdio.h>
#include <math.h>

#define LUNGIME 1001
int main() {
    int N = 0, i = 0;
    float numere[LUNGIME], s = 0;
    char semne[LUNGIME];
    scanf("%d", &N);
    for ( i = 0; i < N; i++ ) {
        scanf("%f", &numere[i]);
    }
    for ( i = 0; i < N - 1; i++ ) {
        scanf(" %c", &semne[i]);
    }
    if ( N != 0 ) {
        s = numere[0];
    }
    for ( i = 0; i < N - 1; i++ ) {
        if ( semne[i] == '+' ) {
            s = s + numere[i + 1];
        } else if ( semne[i] == '-' ) {
            s = s - numere[i + 1];
        } else if ( semne[i] == '*' ) {
            s = s * numere[i + 1];
        } else if ( semne[i] == '/' ) {
            s = s / numere[i + 1];
        }
    }
    printf("%f\n", s);
    return 0;
}
