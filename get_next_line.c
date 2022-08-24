#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (void *)malloc(sizeof(t_list));
	if (lista == NULL)
		return (lista);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}

void	ft_poner(char **s, char *ls)
{
	while (*ls)
	{
		*(*s) = *(ls++);
		(*s)++;
	}
}

void	ft_lstiter(t_list *ls, size_t (*a)(const char *)
, void (*b)(char **s, char *l), char	**s, int *l)
{
	while (ls)
	{
		if (b == NULL)
		{
			*l += a(ls->content);
		}
		if (a == NULL)
		{
			b(s, (char *) ls->content);
		}
		ls = ls->next;
	}
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*st;
	int			e;
	t_list		*ls;
	int			i;
	int			x;

	//printf("%d", fd);

	i = 0;
	e = 0;
	s = ft_calloc(BUFFER_SIZE + 1, 1);
	if (st != NULL)
	{
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)st)));
		//printf("==%s\n", ls->content);
		free(st);
	}

	else
	{
		st = NULL;
		ls = NULL;
	}
	// st = NULL;
	// ls = NULL;
	while (s[i] != '\n' && (read(fd, s, BUFFER_SIZE) > 0 || st != NULL))
	{
		//printf("yujuuu\n");
		//printf("s == %s\n", s);
		i = 0;
		// if (st != NULL)
		// {
		// 	ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)st)));
		// 	free(st);
		// }

		while (s[i] != '\n' && s[i])
		{
			i++;
			if (s[i] == '\n')
			{
				x = i + 1 ;
				st = ft_calloc(ft_strlen(&s[i]), 1);
				while (s[++i])
					st[e++] = s[i];
				s[x] = 0;
				// printf("%s\n", st);
				i = x - 1;
			}
		}		
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)s)));
		if (s[i] != '\n')
			ft_bzero(s, BUFFER_SIZE);
	}
	//s = 0x7f8e18c00640;
	//printf("mal == %c\n", *s);
	if (ls == NULL)
	{
		free(s);
		ft_freelist(ls);
		return(NULL);
	}
	free(s);
	x = 0;
	ft_lstiter(ls, &ft_strlen, NULL, NULL, &x);
	//printf("%d\n", x);
	s = ft_calloc(x + 1, 1);
	ft_lstiter(ls, NULL, (void *)ft_poner, &s, NULL);
	s -= x;
	//printf("s === %s\n", s);
	ft_freelist(ls);
	//printf("%s", s);
	return (s);
}
