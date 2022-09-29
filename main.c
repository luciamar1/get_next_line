#include "get_next_line_bonus.h"

int   main(int ac, char **av)
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open("41_with_nl.txt", O_RDONLY);
  fd2 = open("41_with_nl.txt", O_RDONLY);
  printf("%s\n", get_next_line_bonus(fd1)); 
  printf("%s\n", get_next_line_bonus(fd2));
  printf("%s\n", get_next_line_bonus(fd1));
  printf("%s\n", get_next_line_bonus(fd2));
  // printf("%s\n", get_next_line_bonus(fd1));
  // printf("%s\n", get_next_line_bonus(fd2));
  // printf("%s\n", get_next_line_bonus(fd1));
  // printf("%s\n", get_next_line_bonus(fd2));
  return (0);
}
// void myleak()
// {
// 	system("leaks a.out");
// }

// int main(void)
// {
// 	char *m; 
// 	char	*file;
// 	int		fd;
// 	file = "41_with_nl.txt";
// 	//write(1, "hoal\n", 5);
// 	fd = open(file, O_RDONLY);
// 	//printf("jgpaoj");

// 		m = get_next_line(fd);
// 		printf("%s", m);
// 		free(m);
// 	//atexit(myleak);
// 	//close(fd);
// 	//s = 0x7fd555d005bf;

// 	//printf("jorribool == %s", 0x7fd555d005bf);
// 	//system("leaks a.out");git clone
// }
