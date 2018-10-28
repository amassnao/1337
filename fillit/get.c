/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:31:27 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/24 13:44:18 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	get_left(t_form elem)
{
	t_point smallest;

	smallest.x = elem.p1.x;
	smallest.y = elem.p1.y;
	if (elem.p2.x < smallest.x)
		smallest.x = elem.p2.x;
	if (elem.p1.y < smallest.y)
		smallest.y = elem.p1.y;
	if (elem.p3.x < smallest.x)
		smallest.x = elem.p2.x;
	if (elem.p3.y < smallest.y)
		smallest.y = elem.p3.y;
	if (elem.p4.x < smallest.x)
		smallest.x = elem.p2.x;
	if (elem.p4.y < smallest.y)
		smallest.y = elem.p4.y;
	return (smallest);
}

int		get_height(t_point p1, t_point p2, t_point p3, t_point p4)
{
	int max;
	int min;

	max = p1.y;
	min = p1.y;
	if (p2.y > max)
		max = p2.y;
	if (p2.y < min)
		min = p2.y;
	if (p3.y > max)
		max = p3.y;
	if (p3.y < min)
		min = p3.y;
	if (p4.y > max)
		max = p4.y;
	if (p4.y < min)
		min = p4.y;
	return (max - min + 1);
}

int		get_width(t_point p1, t_point p2, t_point p3, t_point p4)
{
	int max;
	int min;

	max = p1.x;
	min = p1.x;
	if (p2.x > max)
		max = p2.x;
	if (p2.x < min)
		min = p2.x;
	if (p3.x > max)
		max = p3.x;
	if (p3.x < min)
		min = p3.x;
	if (p4.x > max)
		max = p4.x;
	if (p4.x < min)
		min = p4.x;
	return (max - min + 1);
}

int		get_size(t_form forms[27], t_point start)
{
	int i;
	int count;

	i = start.x;
	count = 0;
	while (i < start.y)
	{
		count += forms[i].width * forms[i].height;
		i++;
	}
	return (count);
}

int		get_rest(char **plan, t_point place, t_point size)
{
	int i;
	int j;
	int count;

	count = 0;
	i = place.x;
	j = place.y;
	while (i < size.x)
	{
		while (j < size.y)
		{
			if (plan[i][j] == '.')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
