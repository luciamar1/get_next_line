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

void	ft_amplicirclist(t_circlist	**circu, int fd)
{
	t_circlist	*aux;
	t_circlist	*circ;

	circ = malloc(1*sizeof(t_circlist)); 
	circ = *circu;
	aux = malloc(1*sizeof(t_circlist)); 
	aux->fd = fd;
	circ->next = malloc(1*sizeof(t_circlist));
	circ->next = (struct t_circlist *)aux;
	circ->content = NULL;
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
	while (circu->fd != fd && (struct t_circlist *)circu != circu->start)
		circu = (t_circlist *)circu->next;
	//printf("PUTTTAAAAA\n");
	if (circu->fd != fd)
	{
		ft_amplicirclist(&circu, fd);
		circu->start = start;
	}
	if (n == 1)
		*st = circu->content;
	if (n == 2)
		circu->content = *st;
	if (n == 3)
	{
		ft_freecirclist(circu);
		free(*st);
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
		if ((*s)[++(*i)] == '\n')
		{
			
			x = *i + 1;
			free(*st);
			*st = ft_calloc(ft_strlen(&(s[0][*i])), 1);
			//printf("PUTTTAAAAA\n");
			while ((*s)[++(*i)])
				(*st)[e++] = (*s)[*i];
			(*s)[x] = 0;
			*i = x - 1;
			bonus(st, fd, 2);
			printf("PUTTTAAAAA\n");
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
				//printf("PUTTTAAAAA\n");
				bonus(&st, fd, 3);
				break;
			}
			//printf("PUTTTAAAAA\n");
		iterador(&st, &s, &i, fd);
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)s)));
	}
	if (ls == NULL)
	{
		free(s);
		ft_freelist(ls);
		free(st);
		bonus(&st, fd, 3);
		return (NULL);
	}
	free(s);
	x = 0;
	ft_lstiter(ls, &ft_strlen, NULL, NULL, &x);
	s = ft_calloc(x + 1, 1);
	ft_lstiter(ls, NULL, (void *)ft_poner, &s, NULL);
	s -= x;
	ft_freelist(ls);
	if (!*s)
	{
		free(s);
		return (NULL);
	}
	return (s);
}