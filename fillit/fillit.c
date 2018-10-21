#include "fillit.h"


char **creat_plan(int height, int width)
{
    char **plan;
    int i;
    int j;

    i = 0;
    plan = (char **)malloc(sizeof(char *) * height);
    while (i < height)
        plan[i++] = (char *)malloc(sizeof(char) * width);
    i = 0;
    while (i++ < height)
    {
        j = 0;
        while(j++ < width)
            plan[i - 1][j - 1] = '.';
    }
    return (plan);
}
char **add_to_plan(char **plan, t_form *form, int x, int y)
{
    int r;
    int q;

    r = form->hashs[0].i - x;
    q = form->hashs[0].j - y;
    plan[form->hashs[0].i - r][form->hashs[0].j - q] = form->l;
    plan[form->hashs[1].i - r][form->hashs[1].j - q] = form->l;
    plan[form->hashs[2].i - r][form->hashs[2].j - q] = form->l;
    plan[form->hashs[3].i - r][form->hashs[3].j - q] = form->l;
    return (plan);
}
int solve_forms(t_form *form[26], int len)
{
    char **plan;
    int k;
    int priority;
    int i;
    int x;
    int y;
    int j;

    k = 0;
    i = 0;
    x = 0;
    y = 0;
    j = 0;
    priority = 0;
    plan = creat_plan(4, 4);
    //plan = add_to_plan(plan, form1, 0, 0);
    //plan = add_to_plan(plan, form2, 0, 1);
    while (i < len)
    {
        k = 0;
        j = 0;
        while (k < len)
        {
            if (form[k]->priority == priority && form[k]->exist == 0)
            {
                j++;
                form[k]->exist = 1;
                if (x + form[k]->height > 4)
                    x = 0;
                else if (y + form[k]->width > 4)
                    y = 0;
                plan = add_to_plan(plan, form[k], x, y);
                if (form[k]->height + x < 4)
                    x = form[k]->height + x;
                else if (form[k]->width + y < 4)
                    y = form[k]->width + y;
                break;
            }
            k++;

        }
        if (j == 0)
            priority++;
        else
            i++;
    }


    k = 0;
    while(k++<4)
    {
        ft_putstr(plan[k - 1]);
        ft_putstr("\n");
    }
    ft_putstr("x : ");
    ft_putnbr(x);
    ft_putstr(",y : ");
    ft_putnbr(y);
    return 0;
}

int main()
{
    char *buffer,*buffer2,*buffer3,*buffer4;
    t_form *forms[26];

    buffer = ft_strdup("#...\n#...\n#...\n#...\n");
    buffer2 = ft_strdup("##..\n##..\n....\n....\n");
    buffer3 = ft_strdup("##..\n##..\n....\n....\n");
    buffer4 = ft_strdup("#...\n#...\n#...\n#...\n");

    forms[0] = creat_form(buffer);
    forms[1] = creat_form(buffer2);
    forms[2] = creat_form(buffer3);
    forms[3] = creat_form(buffer4);
    forms[0]->priority = 0;
    forms[1]->priority = 1;
    forms[2]->priority = 1;
    forms[3]->priority = 0;
    forms[0]->exist = 0;
    forms[1]->exist = 0;
    forms[2]->exist = 0;
    forms[3]->exist = 0;
    solve_forms(forms, 4);
    return (0);
}