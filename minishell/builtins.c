#include "builtins.h"
#include "libft/libft.h"

void    ft_putstr_ex(char *str)
{
    while (*str)
    {
        if ((int)*str != 92)
            ft_putchar(*str);
        str++;
    }
}

int    echo(int argc, char **argv)
{
    int lock;

    argc = 0;
    lock = 0;
    argv++;
    while (*argv)
    {
        if (!ft_strcmp(*argv, "-n") && lock == 0)
            argc = 1;
        else
        {
            lock = 1;
            //ft_putstr_ex(*argv);
            ft_putstr(*argv);
            if(*(argv + 1))
                ft_putstr(" ");
        }
        argv++;
    }
    if (argc == 0)
        ft_putchar('\n');
        return (0);
}

int     argvlen(char **argv)
{
    int conter;

    conter = 0;
    while (*argv++)
        conter++;
    return (conter);
}