#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*s;
	static char	*st;
	int			e;
	t_list		ls;
	int			i;

	i = 0;
	ls = NULL;
	e = 0;
	s = ft_calloc(BUFFER_SIZE, 1);
	st = NULL;
	while (*s != '\n')
	{
		if (s[i] != '\n')
		{
			while (s++)
				st[e++] == s;
			*s = 0;
		}
		read(fd, s, ft_strlen(s));
		ft_lstadd_back(ls, substr(s, 0, ft_strlen(s)));
		free(s);
		s++;
	}
	s = ft_calloc(ft_lstiter(ls, size_t(ft_strlen)(char *)));
	ft_poner()
}