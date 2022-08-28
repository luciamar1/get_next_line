#include "get_next_line.h"

void myleak()
{
	system("leaks a.out");
}

int main(void)
{

	char	*file;
	int		fd;

	file = "43_with_nl.txt";
	//write(1, "hoal\n", 5);
	fd = open(file, O_RDONLY);
	//printf("jgpaoj");
	int ret = 1;
	while(ret --)
		printf("%s", get_next_line(fd));	
	//atexit(myleak);
	//close(fd);
	//s = 0x7fd555d005bf;

	//printf("jorribool == %s", 0x7fd555d005bf);
	//system("leaks a.out");
	return (0);
}
