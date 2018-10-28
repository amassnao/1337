/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:30:42 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/24 13:33:17 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creat_plan(t_point size)
{
	char	**plan;
	int		i;
	int		j;

	i = 0;
	plan = (char **)malloc(sizeof(char *) * size.y);
	while (i < size.y)
		plan[i++] = (char *)malloc(sizeof(char) * (size.x + 1));
	i = 0;
	while (i++ < size.y)
	{
		j = 0;
		while (j++ < size.x)
			plan[i - 1][j - 1] = '.';
		plan[i - 1][j - 1] = '\0';
	}
	return (plan);
}

char	**add_to_plan(char **plan, t_form form, t_point coord)
{
	int r;
	int q;

	r = form.left.y - coord.y;
	q = form.left.x - coord.x;
	plan[form.p1.y - r][form.p1.x - q] = form.alpha;
	plan[form.p2.y - r][form.p2.x - q] = form.alpha;
	plan[form.p3.y - r][form.p3.x - q] = form.alpha;
	plan[form.p4.y - r][form.p4.x - q] = form.alpha;
	return (plan);
}

char	**remove_from_plan(char **plan, t_form form, t_point coord)
{
	int r;
	int q;

	r = form.left.y - coord.y;
	q = form.left.x - coord.x;
	plan[form.p1.y - r][form.p1.x - q] = '.';
	plan[form.p2.y - r][form.p2.x - q] = '.';
	plan[form.p3.y - r][form.p3.x - q] = '.';
	plan[form.p4.y - r][form.p4.x - q] = '.';
	return (plan);
}

void	affiche_plan(char **plan, t_point size)
{
	int i;

	i = 0;
	while (i++ < size.x)
	{
		ft_putstr(plan[i - 1]);
		ft_putchar('\n');
	}
}

char	**copy_plan(char **plan, char **plan_tmp, t_point size)
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
