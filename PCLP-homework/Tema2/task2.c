#include "./utils.h"

void SolveTask2(void *info, int nr_avioane, int N, char **mat) {
    unsigned char *pointer = info;
    unsigned char directie = '0', tip = '0', cod[3] = "";
    unsigned short linie = 0, coloana = 0;
    for ( int i = 0; i < nr_avioane; i++ ) {
        linie = *(unsigned short*)pointer;
        pointer = pointer + sizeof(short);
        coloana = *(unsigned short*)pointer;
        pointer = pointer + sizeof(short);
        directie = *(unsigned char*)pointer;
        pointer = pointer + sizeof(char);
        tip = *(unsigned char*)pointer;
        pointer = pointer + sizeof(char) + 3 * sizeof(char) + sizeof(unsigned int);
        if ( tip == '1' ) {
            switch (directie) {
            case 'N':
                mat[linie][coloana] = mat[linie+2][coloana] = '*';
                for ( int j = coloana - 2; j < coloana + 3; j++ ) {
                    mat[linie + 1][j] = '*';
                }
                for ( int j = coloana - 1; j < coloana + 2; j++ ) {
                    mat[linie + 3][j] = '*';
                }
                break;
            case 'S':
                mat[linie][coloana] = mat[linie-2][coloana] = '*';
                for ( int j = coloana - 2; j < coloana + 3; j++ ) {
                    mat[linie - 1] [j] = '*';
                }
                for ( int j = coloana - 1; j < coloana + 2; j++ ) {
                    mat[linie - 3][j] = '*';
                }
                break;
            case 'E':
                mat[linie][coloana] = mat[linie][coloana - 2] = '*';
                for ( int j = linie - 2; j < linie + 3; j++ ) {
                    mat[j][coloana - 1] = '*';
                }
                for ( int j = linie - 1; j < linie + 2; j++ ) {
                    mat[j][coloana - 3] = '*';
                }
                break;
            case 'W':
                mat[linie][coloana] = mat[linie][coloana + 2] = '*';
                for ( int j = linie - 2; j < linie + 3; j++ ) {
                    mat[j][coloana + 1] = '*';
                }
                for ( int j = linie - 1; j < linie + 2; j++ ) {
                    mat[j][coloana  + 3] = '*';
                }
                break;
            default:
                break;
            }
        } else if ( tip == '2' ) {
            switch (directie) {
            case 'N':
                mat[linie][coloana] = mat[linie + 3][coloana] = '*';
                mat[linie + 1][coloana - 1] = mat[linie + 1][coloana] = mat[linie + 1][coloana + 1] = '*';
                for ( int j = coloana - 3; j < coloana + 4; j++ ) {
                    mat[linie + 2][j] = '*';
                }
                for ( int j = coloana - 2; j < coloana + 3; j++ ) {
                    mat[linie + 4][j] = '*';
                }
                break;
            case 'S':
                mat[linie][coloana] = mat[linie - 3][coloana] = '*';
                mat[linie - 1][coloana - 1] = mat[linie - 1][coloana] = mat[linie - 1][coloana + 1] = '*';
                for ( int j = coloana - 3; j < coloana + 4; j++ ) {
                    mat[linie - 2][j] = '*';
                }
                for ( int j = coloana - 2; j < coloana + 3; j++ ) {
                    mat[linie - 4][j] = '*';
                }
                break;
            case 'E':
                mat[linie][coloana] = mat[linie][coloana - 3] = '*';
                mat[linie - 1][coloana - 1] = mat[linie][coloana -1] = mat[linie + 1][coloana -1] = '*';
                for ( int j = linie - 3; j < linie + 4; j++ ) {
                    mat[j][coloana - 2] = '*';
                }
                for ( int j = linie - 2; j < linie + 3; j++ ) {
                    mat[j][coloana - 4] = '*';
                }
                break;
            case 'W':
                mat[linie][coloana] = mat[linie][coloana + 3] = '*';
                mat[linie - 1][coloana + 1] = mat[linie][coloana + 1] = mat[linie + 1][coloana + 1] = '*';
                for ( int j = linie - 3; j < linie + 4; j++ ) {
                    mat[j][coloana + 2] = '*';
                }
                for ( int j = linie - 2; j < linie + 3; j++ ) {
                    mat[j][coloana + 4] = '*';
                }
                break;
            default:
                break;
            }
        }
    }
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ )
            printf("%c ", mat[i][j]);
        printf("\n");
    }
}
