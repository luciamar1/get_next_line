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
	int	i;

	i = 0;
	while (*ls)
		s[0][i++] = *(ls++);
}

void	ft_lstiter(t_list *ls, size_t (*a)(const char *)
, void (*b)(char **s, char *l), char	**s, int *l)
{
	*l = 0;
	while (ls)
	{
		if (b == NULL)
			l += a(ls->content);
		if (a == NULL)
			b(s, ls->content);
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

	i = 0;
	e = 0;
	s = ft_calloc(BUFFER_SIZE + 1, 1);
	st = NULL;
	while (s[i] != '\n' && read(fd, s, BUFFER_SIZE))
	{
		while (s[i] != '\n')
		{
			i++;
			if (s[i] == '\n')
			{
				x = i + 1 ;
				st = ft_calloc(ft_strlen(&s[i]), 1);
				while (s[++i])
					st[e++] = s[i];
				s[x] = 0;
				i = x - 1;
				printf("\n%s\n", st);
			}
		}
		printf("\n%s\n", s);
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)s)));
		printf("ls = %s\n", ls->content);
	}
	/////HASTA AQUI ME PARECE QUE ESTÁ DE PUTA MADRE POR QUE ME IMPRIME EN LA LISTA LO QUE QUIERO
	ft_lstiter(ls, &ft_strlen, NULL, NULL, &x);
	/////AQUI ESTA EL PROBLEMA X DA 0 POR ALGUNA RAZON INSOSPECHABLE
	printf("\n%d\n", x);
	s = ft_calloc(x, 1);
	ft_lstiter(ls, NULL, &ft_poner, &s, NULL);
	return (s);
}
