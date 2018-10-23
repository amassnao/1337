#include "fillit.h"

t_form creat_form(char valid_str[20])
{
    t_form form;
    int i;
    int j;
    int k;
    static int l = 64;

    i = 0;
    j = 0;
    k = 0;
    //form = (t_form *)malloc(sizeof(t_form));
    form.l = (char)++l;
    while(i < 20)
    {
        if (valid_str[i] != '\n' && valid_str[i] == '#')
        {  
            (k == 0) ? form.P1.x = j % 4 : 1 == 1;
            (k == 0) ? form.P1.y = j / 4 : 1 == 1;
            (k == 1) ? form.P2.x = j % 4 : 1 == 1;
            (k == 1) ? form.P2.y = j / 4 : 1 == 1;
            (k == 2) ? form.P3.x = j % 4 : 1 == 1;
            (k == 2) ? form.P3.y = j / 4 : 1 == 1;
            (k == 3) ? form.P4.x = j % 4 : 1 == 1;
            (k == 3) ? form.P4.y = j / 4 : 1 == 1;
            k++;
        }
        if (valid_str[i] != '\n')
            j++;
        i++;
    }
    return (form);
}