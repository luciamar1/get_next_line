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
		*(*s)= *(ls++);
		(*s)++;
	}
	//printf("PRIMERA S ==== %s\n", *s);
}

void	ft_lstiter(t_list *ls, size_t (*a)(const char *)
, void (*b)(char **s, char *l, int x), char	**s, int *l)
{
	while (ls)
	{
		if (b == NULL)
		{
			//printf("iter 1\n");
			*l += a(ls->content);
			//printf("lllllllllll === %d\n", *l);
		}
		if (a == NULL)
		{
			//printf("iter 2\n");
			b(s, (char *) ls->content, *l);
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

	i = 0;
	e = 0;
	s = ft_calloc(BUFFER_SIZE + 1, 1);
	st = NULL;
	while (s[i] != '\n' && read(fd, s, BUFFER_SIZE))
	{
		//printf("%s\n", s);
		i = 0;
		while (s[i] != '\n' && s[i])
		{
			//printf("te tienes que meter 5 veceess");
			i++;
			//printf("%d\n", i);
			if (s[i] == '\n')
			{
				x = i + 1 ;
				//printf("no te metas putaaa\n");
				st = ft_calloc(ft_strlen(&s[i]), 1);
				while (s[++i])
					st[e++] = s[i];
				s[x] = 0;
				printf("\nst === %s\n", st);
				i = x - 1;
			}
		}
		
		ft_lstadd_back(&ls, ft_lstnew(ft_strdup((const char *)s)));
	}
	/////HASTA AQUI ME PARECE QUE ESTÁ DE PUTA MADRE POR QUE ME IMPRIME EN LA LISTA LO QUE QUIERO
	ft_lstiter(ls, &ft_strlen, NULL, NULL, &x);
	x = 0;
	//printf("x ==== %d\n", x);
	/////AQUI ESTA EL PROBLEMA X DA 0 POR ALGUNA RAZON INSOSPECHABLE
	s = ft_calloc(x + 1, 1);
	////printf("len de s ===%ld\n", ft_strlen(s));
	ft_lstiter(ls, NULL, &ft_poner, &s, &x);
	s -= 10;
	//printf("PORFAAAAAAA == %s   pliiiiiiiisss\n", s);
	ft_freelist(ls);
	return (s);
}

