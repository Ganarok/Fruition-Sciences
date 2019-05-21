#include "../libs.h"

void fullstruct(aspi_t *asp, char **line1, char **line2, char **file)
{
    asp->mapx = atoi(line1[0]);
    asp->mapy = atoi(line1[1]);
    asp->x = atoi(line2[0]);
    asp->y = atoi(line2[1]);
    asp->dir = malloc(sizeof(char) * strlen(line2[2]) + 1);
    strcpy(asp->dir, line2[2]);
    asp->path = malloc(sizeof(char) * strlen(file[2]) + 1);
    strcpy(asp->path, file[2]);
    for (int i = 0; line1[i]; i++)
        free(line1[i]);
    free(line1);
    for (int i = 0; line2[i]; i++)
        free(line2[i]);
    free(line2);
}