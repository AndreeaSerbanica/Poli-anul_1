#include "./utils.h"
#define SIZE_OF_ARRAY 13
#define LENGTH_OF_CHAR 5

/*
sortare crescator dupa tip
    pentru tipuri egale, descrescator dupa Codul Aeroportului
        pentru coduri egale, crescator dupa viteza
*/
int compare(const void *x_void, const void *y_void) {
  char x = *(char *)(x_void + 2 * sizeof(unsigned short) + sizeof(unsigned char));
  char y = *(char *)(y_void + 2 * sizeof(unsigned short) + sizeof(unsigned char));
  if (x != y) {
    return x - y;
  }
  const char *a = x_void + 2 * sizeof(unsigned short) + 2 * sizeof(unsigned char);
  const char *b = y_void + 2 * sizeof(unsigned short) + 2 * sizeof(unsigned char);
  if (strncmp(a, b, 3) != 0) {
    return -strncmp(a, b, 3);
  }
  int c = *(const int *)(x_void + 2 * sizeof(unsigned short) + LENGTH_OF_CHAR * sizeof(unsigned char));
  int d = *(const int *)(y_void + 2 * sizeof(unsigned short) + LENGTH_OF_CHAR * sizeof(unsigned char));
    return c - d;
}


void SolveTask3(void *info, int nr_avioane) {
    qsort(info, nr_avioane, SIZE_OF_ARRAY, compare);
    unsigned char *point = info;
    for ( int i = 0; i < nr_avioane; i++ ) {
        printf("(%hu, ", *(unsigned short*)point);
        point  = point + sizeof(unsigned short);
        printf("%hu)", *(unsigned short*)point);
        printf("\n");
        point  = point + sizeof(unsigned short);
        printf("%c\n", *(unsigned char*)point);
        point  = point + sizeof(unsigned char);
        for ( int j = 0; j < 4; j++ ) {
            printf("%c", *(unsigned char*)point);
            point = point + sizeof(char);
        }
        printf("\n");
        printf("%u\n", *(unsigned int*)point);
        printf("\n");
        point  = point + sizeof( unsigned int );
    }
}
