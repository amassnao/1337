#include "fillit.h"

t_form *creat_form(char path[4][4])
{
    t_form *form;
    int i;
    int j;

    form = (t_form *)malloc(sizeof(t_form));
    i = 0;
    j = 0;
    while (i++ < 4)
        while (j++ < 4)
            form->path[i - 1][j - 1] = path[i - 1][j - 1];
    form->x = 0;
    form->y = 0;
    form->next = NULL;
    return (form);
}

t_form  *add_form(t_form *form_root, t_form *form)
{
    form->next = form_root;
    return (form);
}

t_form  *get_form(t_form *form_root, char path[4][4])
{
    int i;
    int j;

    while(form_root != NULL)
    {
        i = 0;
        j = 0;
        while (form_root->path[i][j] == path[i][j] && i < 4)
        {
            j++;
            if (j == 4)
            {
                i++;
                j = 0;
            }
        }
        if (i == 4 && j == 0)
            return (form_root);
        form_root = form_root->next;
    }
    return (NULL);
}

t_form *str_path_form(char valid_str[20])
{
    char    path[4][4];
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 20)
    {
        if (valid_str[i] != '\n')
        {
            path[j / 4][j % 4] = valid_str[j];
            j++;
        }
        i++;
    }
    return (creat_form(path));
}