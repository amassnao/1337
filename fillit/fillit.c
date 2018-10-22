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

void affiche_plan(char **plan, t_point size)
{
    int i;

    i = 0;
    while (i++<size.x)
    {
        ft_putstr(plan[i - 1]);
        ft_putchar('\n');
    }
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
        while (start.x < size.x)
        {
            coord.x = start.x;
            coord.y = start.y;
            if (check_availibity(plan, form, size, coord))
                return (coord);
            start.x++;
        }
        start.x = 0;
        start.y++;
    }
    return (coord);
}

int solve_forms(char **plan, t_form *forms[26], t_point start, t_point size, int i)
{
    t_point place;
    t_point new_start;

    if (forms[i] == NULL)
        return (1);
    new_start.x = 0;
    new_start.y = 0;
    place = get_free_place(plan,forms[i], start, size);
    if (place.x != size.x - 1 || place.y != size.y - 1)
        {
            plan = add_to_plan(plan, forms[i], place);
            if (solve_forms(plan, forms, new_start, size, i + 1) == 0)
            {
                plan = remove_from_plan(plan, forms[i], place);
                start.x++;
                if(start.x == 4)
                {
                    start.x = 0;
                    start.y++;
                }
                return (solve_forms(plan, forms, start, size, i));
            }
        }
    else 
        return (0);
    return (1);
}

int main()
{
    char *buffer,*buffer2,*buffer3,*buffer4,*buffer5,*buffer6,*buffer7,*buffer8;
    t_form *forms[26];
    char **plan;
    t_point size;
    t_point start;
    t_point old_size;


    size.x = size.y = ft_nextsqrt(8 * 4);
    start.x = start.y = 0;
    plan = creat_plan(size);
    buffer = ft_strdup("...#\n...#\n...#\n...#\n");
    buffer2 = ft_strdup("....\n....\n....\n####\n");
    buffer3 = ft_strdup(".###\n...#\n....\n....\n");
    buffer4 = ft_strdup("....\n..##\n.##.\n....\n");
    buffer5 = ft_strdup("....\n.##.\n.##.\n....\n");
    buffer6 = ft_strdup("....\n....\n##..\n.##.\n");
    buffer7 = ft_strdup("##..\n.#..\n.#..\n....\n");
    buffer8 = ft_strdup("....\n###.\n.#..\n....\n");

    forms[0] = creat_form(buffer);
    forms[1] = creat_form(buffer2);
    forms[2] = creat_form(buffer3);
    forms[3] = creat_form(buffer4);
    forms[4] = creat_form(buffer5);
    forms[5] = creat_form(buffer6);
    forms[6] = creat_form(buffer7);
    forms[7] = creat_form(buffer8);
    forms[8] = NULL;
    while (solve_forms(plan, forms, start, size, 0) == 0)
    {
        old_size = size;
        size.x = ++size.y;
        plan = copy_plan(plan, creat_plan(size), old_size);
        //solve_forms(plan, forms, start, size, 0);
    }
    affiche_plan(plan, size);
    return (0);
}