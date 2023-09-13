#include <stdio.h>
#define BIT31 31
#define BIT30 30
#define BIT29 29
#define BIT28 28

int main() {
    unsigned int number = 0, N = 0, Op = 0, Dim = 0;
    int i = 0;
    scanf("%u", &number);
    N =(number >> BIT29) + 1;
    printf("%u ", N);
    number = number << 3;
    for ( i = 0; i < N; i++ ) {
        Op = number >> BIT30;
        if (Op == 0) {
            printf("+ ");
        } else if (Op == 1) {
            printf("- ");
        } else if (Op == 2) {
            printf("* ");
        } else if (Op == 3) {
            printf("/ ");
        }
        number = number << 2;
    }
    Dim =(number >> BIT28) + 1;
    printf("%u\n", Dim);
    return 0;
}
