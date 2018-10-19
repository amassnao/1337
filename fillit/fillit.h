#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# define BUFF_SIZE 20
typedef struct s_form{
    char path[4][4];
    int x;
    int y;
    struct s_form *next;
}               t_form;

typedef struct s_hash{
    int i;
    int j;
    int relation;
}               t_hash;
t_form  *creat_form(char path[4][4]);
t_form  *add_form(t_form *form_root, t_form *form);
t_form  *get_form(t_form *form_root, char path[4][4]);
t_form  *str_path_form(char valid_str[20]);
#endif