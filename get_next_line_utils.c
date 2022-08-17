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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	x;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		d = ft_calloc(1, 1);
		return (d);
	}
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	d = malloc(len + 1 * sizeof(char));
	if (d == NULL)
		return (NULL);
	x = len;
	s += start;
	while (len --)
		*d++ = *s++;
	*d = 0;
	return (d - x);
}
