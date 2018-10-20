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
int solve_forms(t_form *form1, t_form *form2)
{
    char **plan;
    int k;

    k = 0;
    plan = creat_plan(4, 4);
    plan = add_to_plan(plan, form1, 0, 0);
    plan = add_to_plan(plan, form2, 0, 1);
    while(k++<4)
    {
        ft_putstr(plan[k - 1]);
        ft_putstr("\n");
    }
    return 0;
}

int main()
{
    char *buffer;
    char *buffer2;
    t_form *forms[26];

    buffer = ft_strdup("#...\n#...\n#...\n#...\n");
    buffer2 = ft_strdup("##..\n.##.\n....\n....\n");

    forms[0] = creat_form(buffer);
    forms[1] = creat_form(buffer2);
    solve_forms(forms[0], forms[1]);
    return (0);
}