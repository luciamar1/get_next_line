#include "get_next_line_bonus.h"

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
		printf("%s", ls);
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

void	ft_amplicirclist(t_circlist	**circu, int fd, struct t_circlist **start)
{
	t_circlist	*aux;
	t_circlist	*circ;

	circ = malloc(1*sizeof(t_circlist)); 
	circ = *circu;
	aux = malloc(1*sizeof(t_circlist)); 
	aux->fd = fd;
	circ->next = malloc(1*sizeof(t_circlist));
	circ->next = (struct t_circlist *)aux;
	circ->start = malloc(1*sizeof(t_circlist));
	circ->start = *start;
	circ->content = NULL;
	circ->fd = fd;
	*circu = circ;
	circ = NULL;
}

void	bonus(char **st, int fd, int n)
{
	static t_circlist	*circu;
	struct t_circlist *start;
	if (!circu)
	{
		circu = malloc(1*sizeof(t_circlist)); 
		circu->fd = 0;
		circu->next = malloc(1*sizeof(t_circlist));
		circu->next = (struct t_circlist *) circu;
		circu->start = malloc(1*sizeof(t_circlist));
		circu->start = (struct t_circlist *) circu;
		circu = (t_circlist *)circu->next;
		start = circu->start;
	}
	//printf("PUTTTAAAAA\n");
	//printf("yiiiiiiyiyiiyiyiyiyiiyiyiyiyiyiiyiyiyiiyiyi%d\n", fd);
	/////////////////////////////////FALLLLLLLAAAAAA//////////////////////
	while (circu && circu->fd != fd && circu != (t_circlist *) start && printf("\nhola\n"))
		circu = (t_circlist *)circu->next;
	//printf("8798787987PUTTTAAAAA\n");
	if (circu->fd != fd)
	{
		ft_amplicirclist(&circu, fd, &start);
		circu->start = start;
	}
	if (n == 1)
		*st = circu->content;
	if (n == 2)
		circu->content = *st;
	if (n == 3)
	{
		ft_freecirclist(circu);
		//free(*st);
		//printf("GUARRAAAAA\n");
		//printf("PUTTTAAAAA\n");
	}
}

void	iterador(char **st, char **s, int *i, int fd)
{
	int	e;
	int	x;

	x = 0;
	e = 0;
	while ((*s)[*i])
	{
		// printf("sssss== %s\n", *s);
		// printf("estaticaa == %s\n", *st);
		// printf("enterooooo %d\n", *i);
		if ((*s)[++(*i)] == '\n')
		{	
			x = *i + 1;
			free(*st);
			*st = ft_calloc(ft_strlen(&(s[0][*i])), 1);
			while ((*s)[++(*i)])
				(*st)[e++] = (*s)[*i];
			(*s)[x] = 0;
			*i = x - 1;
			//printf("estaticaaaa == %s\n", *st);
			bonus(st, fd, 2);
			break ;
		}
		*i = *i + 1;
	}			
}

char	*ft_copy(char *str)
{
	char	*ret;
	int		counter;

	ret = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!ret)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		ret[counter] = str[counter];
		counter++;
	}
	return (ret);
}

char	*get_next_line_bonus(int fd)
{
	char		*s;
	char		*st;
	t_list		*ls;
	int			i;
	int			x;//static saved[4096];

	st = NULL;
	i = 0;
	s = ft_calloc(BUFFER_SIZE + 1, 1);
	ls = NULL;
	bonus(&st, fd, 1);
	while (s[i] != '\n')
	{
		ft_bzero(s, BUFFER_SIZE + 1);
		i = 0;
		if (st)
		{
			free(s);
			s = ft_copy(st);
			free(st);
			st = NULL;
		}
		else
			if (read(fd, s, BUFFER_SIZE)<= 0)
			{
				bonus(&st, fd, 3);
				break;
			}
			//printf("PUTTTAAAAA\n");
		iterador(&st, &s, &i, fd);
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)s)));
		printf("s = %s\n", s);
		printf("st = %s\n", st);
	}
	while (ls != NULL)
	{
		ls = ls->next;
	}

	//printf("listaaaa == %s\n", ls->content);
	if (ls == NULL)
	{
		free(s);
		ft_freelist(ls);
		free(st);
		//bonus(&st, fd, 3);
		return (NULL);
	}
	free(s);
	x = 0;
	ft_lstiter(ls, &ft_strlen, NULL, NULL, &x);
	s = ft_calloc(x + 1, 1);
	ft_lstiter(ls, NULL, (void *)ft_poner, &s, NULL);
	s -= x;
	printf("%s\n", s);
	ft_freelist(ls);
	if (!*s)
	{
		free(s);
		//printf("GUARRAAAAA\n");
		return (NULL);
	}
	// printf("GUARRAAAAA\n");
	//printf("%s\n", s);
	return (s);
}
