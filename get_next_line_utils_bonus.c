#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = s;
	while (n)
	{
		*a = '\0';
		n--;
		a++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (count > 0xffffffffffffffff / size)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *str)
{
	char			*s;
	unsigned int	sl;

	sl = ft_strlen(str);
	s = malloc(sl * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	while (*str)
	{
		*s = *str;
		s ++;
		str ++;
	}
	*s = '\0';
	return (s - sl);
}

void	ft_freelist(t_list *head)
{
	t_list *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
}

void	ft_freecirclist(t_circlist *list)
{
	t_circlist *tmp;

	tmp = malloc(1*sizeof(t_circlist));
	tmp = list;
	///PROBLEMA/////
	circu = malloc(1*sizeof(t_circlist)); 
		circu->fd = 0;
		circu->next = malloc(1*sizeof(t_circlist));
		circu->next = (struct t_circlist *) circu;
		circu->start = malloc(1*sizeof(t_circlist));
		circu->start = (struct t_circlist *) circu;
		circu = (t_circlist *)circu->next;
		start = circu->start;
	free(tmp->content);
	free(tmp->start);
	free(tmp);
	printf("PUTTTAAAAA\n");
	list = (t_circlist *) list->next;
	printf("PUTTTAAAAA\n");
	tmp = (t_circlist *) list->next;
	while ((struct t_circlist *)list != list->start)
	{
		printf("PUTTTAAAAA\n");
		tmp = list;
		list = (t_circlist *)list->next;
		free(tmp->content);
		free(tmp->start);
		free(tmp);
	}
}
