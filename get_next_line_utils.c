#include "get_next_line.h"

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
	printf("\n%s\n", s);
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