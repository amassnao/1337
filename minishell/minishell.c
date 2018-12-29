#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "builtins.h"
#include <stdio.h>
#include <stdlib.h>


void  calc_arg_len(char *syntax, char c, int *len)
{
    if ((c == 0 && *syntax == ' ' ) || !*syntax)
        return ;
    if (*syntax == c)
        return (calc_arg_len(++syntax, 0, len));

    if (*syntax == '"' && c == 0)
        return (calc_arg_len(++syntax, '"', len));
    if (*syntax == '\'')
        return (calc_arg_len(++syntax, '\'', len));
    (*len)++;
    return (calc_arg_len(++syntax, c, len));
}

int alloc_arg(char *syntax, char c, int offset, char **a, int i, int j)
{
    if ((c == 0 && *syntax == ' ' ) || !*syntax)
        return (offset);

    if (*syntax == c)
    {
        i++;
        j = 0;
        return (alloc_arg(++syntax, 0, ++offset, a, i, j));
    }

    if (*syntax == '"' && c == 0)
    {
        if (j != 0)
            i++;
        j = 0;
        return (alloc_arg(++syntax, '"', ++offset, a, i, j));
    }
    if (*syntax == '\'' && c == 0)
        return (alloc_arg(++syntax, '\'', ++offset, a, i, j));
    a[i][j++] = *syntax;
    //*(a++) = *syntax;
    return (alloc_arg(++syntax, c, ++offset, a, i, j));
}

void show_params(char *syntax)
{
    int len;
    int len2;

    while(*syntax)
    {
        if (*syntax != ' ')
        {
            char **a;
            a = malloc(3);
            for(int i = 0; i < 4; i++)
                a[i] = malloc(200);
            calc_arg_len(syntax, 0, &len);
            syntax += alloc_arg(syntax, 0, 0, a, 0, 0);
            for (int i = 0; i < 3; i++)
                printf("data : %s\n", a[i]);
            continue;
        }
        syntax++;
    }
}

char *esc_caracter(char *syntax)
{
    char *ret;
    int i;

    i = 0;
    ret = malloc(sizeof(char) * ft_strlen(syntax));
    while(*syntax)
    {
        if (*syntax == '\\' && *(syntax + 1) == 'n')
        {
            ret[i++] = '\n';
            syntax++;
        }
        else if (*syntax == '\\' && *(syntax + 1) == 't')
        {
            ret[i++] = '\t';
            syntax++;
        }
        else if (*syntax == '\\' && *(syntax + 1) == 'r')
        {
            ret[i++] = '\r';
            syntax++;
        }
        else
            ret[i++] = *syntax;
        syntax++;
    }
    return (ret);
}

int check_syntax(char *syntax, char c)
{
    if(!*syntax && c == 0)
        return (1);
    else if(!*syntax && c != 0)
        return (-1);

    if (*syntax == c)
        return (check_syntax(++syntax, 0));

    if (*syntax == '"' && c == 0)
        return (check_syntax(++syntax, '"'));
    else if(*syntax != '"' && c == '"')
        return (check_syntax(++syntax, '"'));

    if(*syntax == '\'' && c == 0)
        return (check_syntax(++syntax, '\''));
    else if(*syntax != '\'' && c == '\'')
        return (check_syntax(++syntax, '\''));

    return (check_syntax(++syntax, c));
}

int starcmp(char *s1, char *s2)
{
    if (!*s1 && !*s2)
        return (1);
    else if(*s1 == '*' && !*(s1 + 1))
        return (1);
    else if(*s1 == '*' && *(s1 + 1) == '*')
        return (starcmp(++s1, s2));
    else if(*s1 == '*' && *s2 != *(s1 + 1))
        return ((*(s2 + 1) && *s2) ? starcmp(s1, ++s2) : 0);
    else if(*s1 == '*')
        return (starcmp(++s1, s2));
    else if(*s1 != *s2)
        return (0);
    else// if (*s1 == *s2)
        return (starcmp(++s1, ++s2));
   // return (0);
}

void sigintHandler(int sig_num) 
{ 
    //signal(SIGINT, sigintHandler);
} 

int main(int argc, char **argv, char **envp)
{
    char buffer[2048 + 1];
    char **argvv;
    int r;
    //signal(SIGINT, sigintHandler);
    //signal(SIGTSTP, sigintHandler);
    ft_putstr(ft_strsplit(envp[9], '=')[1]);
    ft_putstr("$> ");
    r = read(1, &buffer, 2048);
    buffer[r - 1] = '\0';
    ft_putnbr(check_syntax(buffer, 0));
    ft_putchar('\n');
    show_params(buffer);
    //check command
    /*if (!argvlen(argv))
        return (main(argc, argvv));
    if (!ft_strcmp("echo", argv[0]))
        echo(argvlen(argv), argv);
    else if(!ft_strcmp("exit", argv[0]))
        return (0);
    else
        ft_putstr("command not faund!\n");*/
    return (main(argc, argv, envp));
}
