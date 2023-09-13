#include "./utils.h"

void SolveTask1(void *info, int nr_avioane) {
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
