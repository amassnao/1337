/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:56:15 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/24 22:36:21 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(int fd, t_form forms[27], int *i)
{
	int		ret;
	int		j;
	int		k;
	char	buff[21];
	char	n[2];

	ret = read(fd, buff, 20);
	if (ret == -1 || (ret >= 0 && ret < 20))
		return (-1);
	buff[ret] = '\0';
	if (buff[0] == '\n' || buff[19] != '\n')
		return (-1);
	if (is_valid_str(buff) == 0)
		return (-1);
	forms[*i] = creat_form(ft_strdup(buff));
	init_form(&forms[*i]);
	(*i)++;
	j = read(fd, n, 1);
	n[j] = '\0';
	if (n[0] != '\n' && j > 0)
		return (-1);
	k = read_file(fd, forms, i);
	if ((k == 0 || k == -1) && (j == 1))
		return (-1);
	return (1);
}

void	solver(t_form forms[27], int i)
{
	char	**plan;
	int		j;
	t_point	size;
	t_point	start[2];
	t_point	old_size;

	j = 1;
	start[0].x = 0;
	start[0].y = 0;
	start[1].x = 0;
	start[1].y = i;
	while (j * j < (i) * 4)
		j++;
	size.x = j;
	size.y = j;
	plan = creat_plan(size);
	while (solve_forms(plan, forms, start, size) == 0)
	{
		old_size = size;
		start[0].x = 0;
		start[0].y = 0;
		size.x = ++size.y;
		plan = copy_plan(plan, creat_plan(size), old_size);
	}
	affiche_plan(plan, size);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	t_form	forms[27];

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (read_file(fd, forms, &i) == -1)
		{
			ft_putstr("error\n");
			return (0);
		}
		solver(forms, i);
	}
	else
		ft_putstr("usage:	./fillit source_file\n");
	return (0);
}
