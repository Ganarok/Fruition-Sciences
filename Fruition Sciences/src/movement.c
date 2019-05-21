#include "../libs.h"

void turn(aspi_t *asp)
{
    if (asp->dir[0] == 'N') {
        asp->dir[0] = 'E';
    } else if (asp->dir[0] == 'E') {
        asp->dir[0] = 'S';
    } else if (asp->dir[0] == 'S') {
        asp->dir[0] = 'W';
    } else if (asp->dir[0] == 'W') {
        asp->dir[0] = 'N';
    }
}

void move(aspi_t *asp)
{
    if (asp->dir[0] == 'N') {
        asp->y += 1;
    } else if (asp->dir[0] == 'E') {
        asp->x -= 1;
    } else if (asp->dir[0] == 'S') {
        asp->y -= 1;
    } else if (asp->dir[0] == 'W') {
        asp->x += 1;
    }
}

void movement(aspi_t *asp)
{
    for (int i = 0; asp->path[i]; i++) {
        if (asp->path[i] == 'A')
            move(asp);
        else
            turn(asp);
    }
}