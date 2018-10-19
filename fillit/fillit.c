#include "fillit.h"

int final_test(t_hash hashs[4], int valid)
{
    int i;

    i = 0;
    while(i < 4)
    {
        if (valid == 0 || hashs[i].relation < 1)
            return (0);
        i++;
    }
    return (1);
}

int test_relations(t_hash hashs[4])
{
    int i;
    int j;
    int valid;

    i = 0;
    valid = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (hashs[i].i == hashs[j].i && hashs[i].j + 1 == hashs[j].j)
                hashs[i].relation++;
            else if (hashs[i].i == hashs[j].i && hashs[i].j - 1 == hashs[j].j)
                hashs[i].relation++;
            else if (hashs[i].i + 1 == hashs[j].i && hashs[i].j == hashs[j].j)
                hashs[i].relation++;
            else if (hashs[i].i - 1 == hashs[j].i && hashs[i].j == hashs[j].j)
                hashs[i].relation++;
            j++;
        }
        if (hashs[i].relation >= 2)
            valid = 1;
        ft_putstr("has : ");
        ft_putnbr(hashs[i].relation);
        ft_putstr("\n");
        i++;
    }
    return (final_test(hashs, valid));
}

int is_valid_str(char str[20])
{
    t_hash hashs[4];
    int i;
    int j;
    int k;
    int conter;

    k = 0;
    i = 0;
    j = 0;
    conter = 0;
    while (i < 20)
    {
        if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
            return (0);
        if (str[i] != '\n' && str[i] == '#')
        {
            hashs[k].relation = 0;
            hashs[k].i = j / 4;
            hashs[k++].j = j % 4;
            conter++;
        }
        if (str[i] != '\n')
            j++;
        i++;
    }
    if (conter != 4)
        return (0);
    return (test_relations(hashs));
}
int main()
{
    char *buffer;

    buffer = ft_strdup("....\n.##.\n##..\n....\n");
    ft_putstr(buffer);
    if (is_valid_str(buffer) == 0)
        ft_putstr("sorry no !\n");
    else
        ft_putstr("good yes :)\n");
    return (0);
}