#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h> 
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_circlist
{
	char			*content;
	struct t_circlist	*start;
	int				fd;
	struct t_circlist	*next;
}	t_circlist;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_freelist(t_list *head);
void	bonus(char **st, int fd, int n);
void	ft_amplicirclist(t_circlist	**circu, int fd, struct t_circlist **start);
char	*get_next_line(int fd);
void	ft_freecirclist(t_circlist *head);
#endif

