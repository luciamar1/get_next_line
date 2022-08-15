#include "get_next_line.h"

char    *get_next_line(int  fd)
{
    char    *s;
    static  st;
    int     e;

    e = 0;
    s = ft_calloc(BUFFER_SIZE, 1);
    while(*s != '\n')
    {
        if(s[i] != '\n')
        {
            while(s[i])
                st == s[i++];    
        }
        read(fd, s, ft_strlen(s));
        while(*s && *s != '\n')
            s ++;
        if (!s)
            return()
    }
    if (*s == '\n')
        *s = 0;
}