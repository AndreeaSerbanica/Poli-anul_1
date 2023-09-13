#include "./utils.h"

void SolveTask4(void *info, int nr_avioane, int nr_obstacole, int *x, int *y, int N) {
    unsigned char *pointer = info;
    unsigned char directie = '0', tip = '0';
    unsigned short linie = 0, coloana = 0;
    int contor = 0, ok = 0;
    for ( int i = 0; i < nr_avioane; i++ ) {
        linie = *(unsigned short*)pointer;
        pointer = pointer + sizeof(short);
        coloana = *(unsigned short*)pointer;
        pointer = pointer + sizeof(short);
        directie = *(unsigned char*)pointer;
        pointer = pointer + sizeof(char);
        tip = *(unsigned char*)pointer;
        pointer = pointer + sizeof(char) + 3 * sizeof(char) + sizeof(unsigned int);
        ok = 0;
        if ( tip == '1' ) {
            switch (directie) {
            case 'N':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(x + k) <= linie + 1) {
                    if (*(y + k) >= coloana - 2 && *(y + k) <= coloana + 2) {
                        ok = 1;
                    }
                } else if (*(x + k) > linie + 1 && *(x + k) <= linie + 3) {
                    if (*(y + k) >= coloana - 1 && *(y + k) <= coloana + 1) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'S':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(x + k) >= linie - 1) {
                    if (*(y + k) >= coloana - 2 && *(y + k) <= coloana + 2) {
                        ok = 1;
                    }
                } else if (*(x + k) < linie - 1 && *(x + k) >= linie - 3) {
                    if (*(y + k) >= coloana - 1 && *(y + k) <= coloana + 1) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'E':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(y + k) >= coloana - 1) {
                    if (*(x + k) >= linie - 2 && *(x + k) <= linie + 2) {
                        ok = 1;
                    }
                } else if (*(y + k) < coloana - 1 && *(y + k) >= coloana - 3) {
                    if (*(x + k) >= linie - 1 && *(x + k) <= linie + 1) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'W':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(y + k) <= coloana + 1) {
                    if (*(x + k) >= linie - 2 && *(x + k) <= linie + 2) {
                        ok = 1;
                    }
                } else if (*(y + k) > coloana + 1 && *(y + k) <= coloana + 3) {
                    if (*(x + k) >= linie - 1 && *(x + k) <= linie + 1) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            default:
                break;
            }
         } else if ( tip == '2' ) {
            switch (directie) {
            case 'N':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(x + k) <= linie + 2) {
                    if (*(y + k) >= coloana - 3 && *(y + k) <= coloana + 3) {
                        ok = 1;
                    }
                } else if (*(x + k) > linie + 2 && *(x + k) <= linie + 4) {
                    if (*(y + k) >= coloana - 2 && *(y + k) <= coloana + 2) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'S':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(x + k) >= linie - 2) {
                    if (*(y + k) >= coloana - 3 && *(y + k) <= coloana + 3) {
                        ok = 1;
                    }
                } else if (*(x + k) < linie - 2 && *(x + k) >= linie - 4) {
                    if (*(y + k) >= coloana - 2 && *(y + k) <= coloana + 2) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'E':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(y + k) >= coloana - 2) {
                    if (*(x + k) >= linie - 3 && *(x + k) <= linie + 3) {
                        ok = 1;
                    }
                } else if (*(y + k) < coloana - 2 && *(y + k) >= coloana - 4) {
                    if (*(x + k) >= linie - 2 && *(x + k) <= linie + 2) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            case 'W':
            for ( int k = 0; k < nr_obstacole; k++ ) {
                if (*(y + k) <= coloana + 2) {
                    if (*(x + k) >= linie - 3 && *(x + k) <= linie + 3) {
                        ok = 1;
                    }
                } else if (*(y + k) > coloana + 2 && *(y + k) <= coloana + 4) {
                    if (*(x + k) >= linie - 2 && *(x + k) <= linie + 2) {
                        ok = 1;
                    }
                }
            }
            if (ok == 1) {
                contor++;
            }
                break;
            default:
                break;
            }
        }
    }
    printf("%d", nr_avioane - contor);
}

