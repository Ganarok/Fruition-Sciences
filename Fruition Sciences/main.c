#include "libs.h"

int fill_struct(char **file, aspi_t *asp)
{
    char **line1 = my_str_to_tab(file[0], ' ');
    char **line2 = my_str_to_tab(file[1], ' ');

    fullstruct(asp, line1, line2, file);
    if (asp->mapx < asp->x || asp->mapy < asp->y) {
        fprintf(stderr, "Error on pos : the map is too small.\n");
        return (0);
    }
    return (1);
}

int my_check(int fd, int check_error, int check)
{
    if (check == 1 && fd == -1) {
        fprintf(stderr, "Error in function open: No such file");
        fprintf(stderr, " or directory.\n");
        return (1);
    } else if (check == 2 && check_error <= 0) {
        fprintf(stderr, "The file is empty.\n");
        return (1);
    }
    return (0);
}

char *open_file(char *filepath)
{
    int fd;
    int check_error;
    struct stat file;
    char *buff = NULL;

    stat(filepath, &file);
    fd = open(filepath, 0, O_RDONLY);
    my_check(fd, 0, 1);
    buff = malloc(sizeof(char) * file.st_size + 1);
    check_error = read(fd, buff, file.st_size);
    buff[file.st_size] = 0;
    close(fd);
    if (my_check(fd, check_error, 2)) {
        free(buff);
        exit(84);
    }
    return (buff);
}

int main(int ac, char **av)
{
    aspi_t asp;
    char *path = open_file(av[1]);
    char **file = my_str_to_tab(path, '\n');

    if (ac != 2) {
        fprintf(stderr, "Error : You need at least 1 argument.\n");
        return (84);
    } else if (!fill_struct(file, &asp))
        return (84);
    movement(&asp);
    printf("%d %d %s\n", asp.x, asp.y, asp.dir);
    for (int i = 0; file[i]; i++)
        free(file[i]);
    free(path);
    free(file);
    free(asp.dir);
    free(asp.path);
    return (0);
}
