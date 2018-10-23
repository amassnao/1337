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
char **add_to_plan(char **plan, t_form form, t_point coord)
{
    int r;
    int q;

    r = form.P1.y - coord.y;
    q = form.P1.x - coord.x;
    plan[form.P1.y - r][form.P1.x - q] = form.l;
    plan[form.P2.y - r][form.P2.x - q] = form.l;
    plan[form.P3.y - r][form.P3.x - q] = form.l;
    plan[form.P4.y - r][form.P4.x - q] = form.l;
    return (plan);
}

char **remove_from_plan(char **plan, t_form form, t_point coord)
{
    int r;
    int q;

    r = form.P1.y - coord.y;
    q = form.P1.x - coord.x;
    plan[form.P1.y - r][form.P1.x - q] = '.';
    plan[form.P2.y - r][form.P2.x - q] = '.';
    plan[form.P3.y - r][form.P3.x - q] = '.';
    plan[form.P4.y - r][form.P4.x - q] = '.';
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

int check_availibity(char **plan, t_form form, t_point size, t_point coord)
{
    int r;
    int q;

    r = form.P1.y - coord.y;
    q = form.P1.x - coord.x;
    if (form.P1.y - r + 1 > size.y || form.P1.x - q + 1 > size.x)
        return (0);
    if (form.P2.y - r + 1 > size.y || form.P2.x - q + 1 > size.x)
        return (0);
    if (form.P3.y - r + 1 > size.y || form.P3.x - q + 1 > size.x)
        return (0);
    if (form.P4.y - r + 1 > size.y || form.P4.x - q + 1 > size.x)
        return (0);
    if (plan[form.P1.y - r][form.P1.x - q] != '.')
        return (0);
    if (plan[form.P2.y - r][form.P2.x - q] != '.')
        return (0);
    if (plan[form.P3.y- r][form.P3.x - q] != '.')
        return (0);
    if (plan[form.P4.y - r][form.P4.x - q] != '.')
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

t_point get_free_place_new(char **plan, t_form form, t_point start, t_point size)
{
    if (check_availibity(plan, form, size, start))
        return (start);
    else
    {
        start.x++;
        if(start.x == size.x)
        {
            start.x = 0;
            start.y++;
        }
        if (start.y == size.y)
        {
            start.x = size.x - 1;
            start.y = size.y - 1;
            return (start);
        }
        return (get_free_place_new(plan, form, start, size));
    }
}

t_point get_free_place(char **plan, t_form form, t_point start, t_point size)
{
    while(start.y < size.y)
    {
        while (start.x < size.x)
        {
            if (check_availibity(plan, form, size, start))
                return (start);
            start.x++;
        }
        start.x = 0;
        start.y++;
    }
    start.x = size.x - 1;
    start.y = size.y - 1;
    return (start);
}

int solve_forms(char **plan, t_form forms[27], t_point start[2], t_point size)
{
    t_point place;
    t_point new_start;

    if (start[1].x == start[1].y)
        return (1);
    new_start.x = 0;
    new_start.y = 0;
    place = get_free_place(plan, forms[start[1].x], start[0], size);
    if (place.x != size.x - 1 || place.y != size.y - 1)
        {
            plan = add_to_plan(plan, forms[start[1].x], place);
            affiche_plan(plan, size);
            ft_putchar('\n');
            start[0] = new_start;
            start[1].x++;
            if (solve_forms(plan, forms, start, size) == 0)
            {   
                start[1].x--;
                plan = remove_from_plan(plan, forms[start[1].x], place);
                if(start[1].y - start[1].x + 1 > start[1].y / 2)
                    return(0);
                place.x++;
                if(place.x == size.x)
                {
                    place.x = 0;
                    place.y++;
                }
                if (place.y == size.y)
                    return(0);
                start[0] = place;
                return (solve_forms(plan, forms, start, size));
            }
        }
    else 
        return (0);
    return (1);
}

int main()
{
    char *buffer,*buffer2,*buffer3,*buffer4,*buffer5,*buffer6,*buffer7,*buffer8,*buffer9,*buffer10,*buffer11,*buffer12,*buffer13,*buffer14,*buffer15,*buffer16;
    char *buffer17,*buffer18,*buffer19,*buffer20,*buffer21,*buffer22,*buffer23,*buffer24,*buffer25,*buffer26;
    t_form forms[27];
    char **plan;
    t_point size;
    t_point start[2];
    t_point old_size;


    size.x = size.y = ft_nextsqrt((26 * 4) + 1);
    //ft_putnbr(size.x);
    start[0].x = start[0].y = 0;
    start[1].x = 0;
    start[1].y = 26;
    plan = creat_plan(size);
    buffer = ft_strdup("...#\n...#\n...#\n...#\n");
    buffer2 = ft_strdup("....\n....\n....\n####\n");
    buffer3 = ft_strdup(".###\n...#\n....\n....\n");
    buffer4 = ft_strdup("....\n..##\n.##.\n....\n");
    buffer5 = ft_strdup("....\n.##.\n.##.\n....\n");
    buffer6 = ft_strdup("....\n....\n##..\n.##.\n");
    buffer7 = ft_strdup("##..\n.#..\n.#..\n....\n");
    buffer8 = ft_strdup("....\n###.\n.#..\n....\n");
    buffer9 = ft_strdup("...#\n...#\n...#\n...#\n");
    buffer10 = ft_strdup("....\n....\n....\n####\n");
    buffer11 = ft_strdup(".###\n...#\n....\n....\n");
    buffer12 = ft_strdup("....\n..##\n.##.\n....\n");
    buffer13 = ft_strdup("....\n.##.\n.##.\n....\n");
    buffer14 = ft_strdup("....\n....\n##..\n.##.\n");
    buffer15 = ft_strdup("##..\n.#..\n.#..\n....\n");
    buffer16 = ft_strdup("....\n###.\n.#..\n....\n");
    buffer17 = ft_strdup("...#\n...#\n...#\n...#\n");
    buffer18 = ft_strdup("....\n....\n....\n####\n");
    buffer19 = ft_strdup(".###\n...#\n....\n....\n");
    buffer20 = ft_strdup("....\n..##\n.##.\n....\n");
    buffer21 = ft_strdup("....\n.##.\n.##.\n....\n");
    buffer22 = ft_strdup("....\n....\n##..\n.##.\n");
    buffer23 = ft_strdup("##..\n.#..\n.#..\n....\n");
    buffer24 = ft_strdup("....\n###.\n.#..\n....\n");
    buffer25 = ft_strdup("...#\n...#\n...#\n...#\n");
    buffer26 = ft_strdup("....\n....\n....\n####\n");

    forms[0] = creat_form(buffer);
    forms[1] = creat_form(buffer2);
    forms[2] = creat_form(buffer3);
    forms[3] = creat_form(buffer4);
    forms[4] = creat_form(buffer5);
    forms[5] = creat_form(buffer6);
    forms[6] = creat_form(buffer7);
    forms[7] = creat_form(buffer8);
    forms[8] = creat_form(buffer9);
    forms[9] = creat_form(buffer10);
    forms[10] = creat_form(buffer11);
    forms[11] = creat_form(buffer12);
    forms[12] = creat_form(buffer13);
    forms[13] = creat_form(buffer14);
    forms[14] = creat_form(buffer15);
    forms[15] = creat_form(buffer16);
    forms[16] = creat_form(buffer17);
    forms[17] = creat_form(buffer18);
    forms[18] = creat_form(buffer19);
    forms[19] = creat_form(buffer20);
    forms[20] = creat_form(buffer21);
    forms[21] = creat_form(buffer22);
    forms[22] = creat_form(buffer23);
    forms[23] = creat_form(buffer24);
    forms[24] = creat_form(buffer25);
    forms[25] = creat_form(buffer26);
    //forms[26] = NULL;
    while (solve_forms(plan, forms, start, size) == 0)
    {
        old_size = size;
        size.x = ++size.y;
        plan = copy_plan(plan, creat_plan(size), old_size);
        //solve_forms(plan, forms, start, size, 0);
    }
    affiche_plan(plan, size);
    return (0);
}