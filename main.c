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
	file = "empty.txt";
	//write(1, "hoal\n", 5);
	fd = -1;
	//printf("jgpaoj");
	int ret = 0;
	while(ret --)
	{
		m = get_next_line(fd--);
		printf("%s", m);
		free(m);
	}	
	atexit(myleak);
	//close(fd);
	//s = 0x7fd555d005bf;

	//printf("jorribool == %s", 0x7fd555d005bf);
	//system("leaks a.out");git clone
}
