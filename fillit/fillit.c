/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:31:20 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/24 13:57:53 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	optimize(t_point *place, t_point size, t_point start[2], t_point p)
{
	if (p.x >= (start[1].y - start[1].x + 1) * 4 + 2)
	{
		if (p.y < p.x)
			return (0);
	}
	place->x++;
	if (place->x == size.x)
	{
		place->x = 0;
		place->y++;
	}
	if (place->y == size.y)
		return (0);
	return (1);
}

int	solve_forms(char **plan, t_form forms[27],
		t_point start[2], t_point size)
{
	t_point	place;
	t_point	p;

	if (start[1].x == start[1].y)
		return (1);
	place = get_free_place(plan, forms[start[1].x], start[0], size);
	if (place.x != size.x - 1 || place.y != size.y - 1)
	{
		plan = add_to_plan(plan, forms[start[1].x], place);
		start[0] = init_point();
		start[1].x++;
		p.x = get_size(forms, start[1]);
		p.y = get_rest(plan, place, size);
		if (solve_forms(plan, forms, start, size) == 0)
		{
			plan = remove_from_plan(plan, forms[--start[1].x], place);
			if (optimize(&place, size, start, p) == 0)
				return (0);
			start[0] = place;
			return (solve_forms(plan, forms, start, size));
		}
	}
	else
		return (0);
	return (1);
}
