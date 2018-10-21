#include "fillit.h"

int ft_nextsqrt(int nb)
{
    int i;

    while (nb)
    {
        i = 1;
        while (i * i <= nb)
        {
            if (i * i == nb)
                return (i);
            i++;
        }
        nb++;
    }
    return (0);
}

char **creat_plan(t_point size)
{
    char **plan;
    int i;
    int j;

    i = 0;
    plan = (char **)malloc(sizeof(char *) * size.y);
    while (i < size.y)
        plan[i++] = (char *)malloc(sizeof(char) * size.x);
    i = 0;
    while (i++ < size.y)
    {
        j = 0;
        while(j++ < size.x)
            plan[i - 1][j - 1] = '.';
    }
    return (plan);
}
char **add_to_plan(char **plan, t_form *form, t_point coord)
{
    int r;
    int q;

    r = form->hashs[0].i - coord.y;
    q = form->hashs[0].j - coord.x;
    plan[form->hashs[0].i - r][form->hashs[0].j - q] = form->l;
    plan[form->hashs[1].i - r][form->hashs[1].j - q] = form->l;
    plan[form->hashs[2].i - r][form->hashs[2].j - q] = form->l;
    plan[form->hashs[3].i - r][form->hashs[3].j - q] = form->l;
    return (plan);
}

char **remove_from_plan(char **plan, t_form *form, t_point coord)
{
    int r;
    int q;

    r = form->hashs[0].i - coord.y;
    q = form->hashs[0].j - coord.x;
    plan[form->hashs[0].i - r][form->hashs[0].j - q] = '.';
    plan[form->hashs[1].i - r][form->hashs[1].j - q] = '.';
    plan[form->hashs[2].i - r][form->hashs[2].j - q] = '.';
    plan[form->hashs[3].i - r][form->hashs[3].j - q] = '.';
    return (plan);
}

int check_availibity(char **plan, t_form *form, t_point size, t_point coord)
{
    int r;
    int q;

    r = form->hashs[0].i - coord.y;
    q = form->hashs[0].j - coord.x;
    if (form->hashs[0].i - r + 1 > size.y || form->hashs[0].j - q + 1 > size.x)
        return (0);
    if (form->hashs[1].i - r + 1 > size.y || form->hashs[1].j - q + 1 > size.x)
        return (0);
    if (form->hashs[2].i - r + 1 > size.y || form->hashs[2].j - q + 1 > size.x)
        return (0);
    if (form->hashs[3].i - r + 1 > size.y || form->hashs[3].j - q + 1 > size.x)
        return (0);
    if (plan[form->hashs[0].i - r][form->hashs[0].j - q] != '.')
        return (0);
    if (plan[form->hashs[1].i - r][form->hashs[1].j - q] != '.')
        return (0);
    if (plan[form->hashs[2].i - r][form->hashs[2].j - q] != '.')
        return (0);
    if (plan[form->hashs[3].i - r][form->hashs[3].j - q] != '.')
        return (0);
    return (1);
}

char    **copy_plan(char **plan, char **plan_tmp, t_point size)
{
    int i;
    int j;

    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            plan_tmp[i][j] = plan[i][j];
            j++;
        }
        i++;
    }
    return (plan_tmp);
}


t_point get_free_place(char **plan, t_form *form, t_point start, t_point size)
{
    t_point coord;

    while(start.y < size.y)
    {
        start.x = 0;
        while (start.x < size.x)
        {
            coord.x = start.x;
            coord.y = start.y;
            if (check_availibity(plan, form, size, coord))
                return (coord);
            start.x++;
        }
        start.y++;
    }
    return (coord);
}

int solve_forms(char **plan, t_form *forms[26], t_point start, t_point size, int i)
{
    int k;
    t_point ss;

    k = 0;
    if (forms[i] == NULL)
        return (0);
    if  (get_free_place(plan, forms[i], start, size).x == size.x && 
    get_free_place(plan, forms[i], start, size).y == size.y)
        return(1);
    ss = get_free_place(plan, forms[0], start, size);
    plan = add_to_plan(plan, forms[i],ss);
    while(k++<size.x)
    {
        ft_putstr(plan[k - 1]);
        ft_putstr("\n");
    }
    ft_putstr("\n");
    plan = remove_from_plan(plan, forms[i], ss);
    ss.x++;
    return (solve_forms(plan, forms, ss, size, i));
}

int main()
{
    char *buffer,*buffer2,*buffer3,*buffer4;
    t_form *forms[26];
    char **plan;
    t_point size;
    t_point start;

    size.x = size.y = 4;
    start.x = start.y = 0;
    plan = creat_plan(size);
    buffer = ft_strdup("#...\n#...\n#...\n#...\n");
    buffer2 = ft_strdup("####\n....\n....\n....\n");
    buffer3 = ft_strdup("##..\n##..\n....\n....\n");
    buffer4 = ft_strdup("#...\n#...\n#...\n#...\n");

    forms[0] = creat_form(buffer);
    //forms[1] = creat_form(buffer3);
    forms[1] = NULL;
    //forms[2] = creat_form(buffer3);
    //forms[3] = creat_form(buffer2);
    solve_forms(plan, forms, start, size, 0);
    return (0);
}