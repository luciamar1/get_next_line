#include "get_next_line.h"

void myleak()
{
	(system("leaks a.out"));
}

int main(void)
{

	char	*file;
	int		fd;

	file = "41_with_nl.txt";
	fd = open(file, O_RDONLY);

	int ret = 2;
	while(ret --)
		printf("%s", get_next_line(fd));
	//atexit(myleak);
	//close(fd);
	//s = 0x7fd555d005bf;

	//printf("jorribool == %s", 0x7fd555d005bf);
	//system("leaks a.out");
	return (0);
}
