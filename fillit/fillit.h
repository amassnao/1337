#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# define BUFF_SIZE 20

typedef struct s_hash{
    int i;
    int j;
    int relation;
}               t_hash;

typedef struct s_form{
    t_hash hashs[4];
    int x;
    int y;
    int width;
    int height;
    char l;
    int priority;
    int exist;
}               t_form;

t_form  *creat_form(char valid_str[20]);
#endif