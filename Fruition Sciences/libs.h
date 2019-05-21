#ifndef lib
#define lib
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct aspi_s {
    int mapx;
    int mapy;
    int x;
    int y;
    char *dir;
    char *path;
} aspi_t;

void movement(aspi_t *asp);
char **my_str_to_tab(char *str, char sep);
void fullstruct(aspi_t *asp, char **line1, char **line2, char **file);

#endif
