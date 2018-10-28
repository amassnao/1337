/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:33:57 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/24 22:36:02 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_availibity(char **plan, t_form form, t_point size, t_point coord)
{
	int r;
	int q;

	r = form.left.y - coord.y;
	q = form.left.x - coord.x;
	if ((form.p1.y - r + 1) > size.y || form.p1.x - q + 1 > size.x)
		return (0);
	if (form.p2.y - r + 1 > size.y || form.p2.x - q + 1 > size.x)
		return (0);
	if (form.p3.y - r + 1 > size.y || form.p3.x - q + 1 > size.x)
		return (0);
	if (form.p4.y - r + 1 > size.y || form.p4.x - q + 1 > size.x)
		return (0);
	if (plan[form.p1.y - r][form.p1.x - q] != '.')
		return (0);
	if (plan[form.p2.y - r][form.p2.x - q] != '.')
		return (0);
	if (plan[form.p3.y - r][form.p3.x - q] != '.')
		return (0);
	if (plan[form.p4.y - r][form.p4.x - q] != '.')
		return (0);
	return (1);
}

t_point	get_free_place(char **plan, t_form form, t_point start, t_point size)
{
	while (start.y < size.y)
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

t_point	init_point(void)
{
	t_point point;

	point.x = 0;
	point.y = 0;
	return (point);
}

void	init_form(t_form *tetro)
{
	tetro->width = get_width(tetro->p1, tetro->p2, tetro->p3, tetro->p4);
	tetro->height = get_height(tetro->p1, tetro->p2, tetro->p3, tetro->p4);
	tetro->left = get_left(*tetro);
}
