#include <get_next_line.h>

int main(void)
{
    char    *file;
    int     fd;

    file = "eragon.txt";
    fd = open(file, O_RDONLY);

    get_next_line(fd);
    close(fd);
}