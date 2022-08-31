#include "get_next_line.h"

void myleak()
{
	system("leaks a.out");
}

int main(void)
{
	char *m;

	char	*file;
	int		fd;
	file = "43_no_nl.txt";
	//write(1, "hoal\n", 5);
	fd = open(file, O_RDONLY);
	//printf("jgpaoj");
	int ret = 1;
	while(ret --)
	{
		m = get_next_line(fd);
		printf("%s", m);
		free(m);
	}	
	//atexit(myleak);
	//close(fd);
	//s = 0x7fd555d005bf;

	//printf("jorribool == %s", 0x7fd555d005bf);
	//system("leaks a.out");
	return (0);
}
