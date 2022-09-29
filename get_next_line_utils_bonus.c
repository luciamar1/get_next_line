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

void	ft_freelist(t_list *lclean)
{
	t_list *list;

	while (lclean != NULL)
	{
		list = lclean;
		lclean = lclean->next;
		free(list->content);
		free(list);
	}
}

void	ft_freecirclist(t_circlist *lclean)
{
	struct t_circlist	*start;
	struct t_circlist	*aux;

	while (lclean != start)
	{
		start = (struct t_circlistt *)lclean->start;
		aux = lclean->next;
		free(lclean->content);
		free(lclean);
		lclean = aux;
	}
}
