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

typedef struct s_point
{
    int x;
    int y;
}               t_point;

typedef struct s_form{
    t_point P1;
    t_point P2;
    t_point P3;
    t_point P4;
    char l;
}               t_form;

t_form  creat_form(char valid_str[20]);
#endif