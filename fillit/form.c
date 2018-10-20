#include "fillit.h"

int get_height(t_hash hashs[4])
{
    int max;
    int min;
    int k;

    max = hashs[0].i;
    min = hashs[0].i;
    k = 1;
    while (k < 4)
    {
        if (hashs[k].i > max)
            max = hashs[k].i;
        if (hashs[k].i < min)
            min = hashs[k].i;
        k++;
    }
    return (max - min + 1);
}

int get_width(t_hash hashs[4])
{
    int max;
    int min;
    int k;

    max = hashs[0].j;
    min = hashs[0].j;
    k = 1;
    while (k < 4)
    {
        if (hashs[k].j > max)
            max = hashs[k].j;
        if (hashs[k].j < min)
            min = hashs[k].j;
        k++;
    }
    return (max - min + 1);
}

t_form *creat_form(char valid_str[20])
{
    t_form *form;
    int i;
    int j;
    int k;
    static int l = 64;

    i = 0;
    j = 0;
    k = 0;
    form = (t_form *)malloc(sizeof(t_form));
    form->x = 0;
    form->y = 0;
    form->l = (char)++l;
    while(i < 20)
    {
        if (valid_str[i] != '\n' && valid_str[i] == '#')
        {   
            form->hashs[k].i = j / 4;
            form->hashs[k++].j = j % 4;
        }
        if (valid_str[i] != '\n')
            j++;
        i++;
    }
    form->width = get_width(form->hashs);
    form->height = get_height(form->hashs);
    return (form);
}