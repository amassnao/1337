/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscorrectform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:31:06 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/24 13:51:07 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		final_test(t_hash hashs[4], int valid)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (valid == 0 || hashs[i].relation < 1)
			return (0);
		i++;
	}
	return (1);
}

int		test_relations(t_hash hashs[4])
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
		if (hashs[i++].relation >= 2)
			valid = 1;
	}
	return (final_test(hashs, valid));
}

int		is_valid_str(char str[20])
{
	t_hash	hashs[4];
	t_point	counter;
	int		k;
	int		conter;

	k = 0;
	counter = init_point();
	conter = 0;
	while (counter.x < 20)
	{
		if (str[counter.x] != '#' && str[counter.x] != '.'
				&& str[counter.x] != '\n')
			return (0);
		if (str[counter.x] != '\n' && str[counter.x] == '#')
		{
			if (++conter == 5)
				return (0);
			hashs[k].relation = 0;
			hashs[k].i = counter.y / 4;
			hashs[k++].j = counter.y % 4;
		}
		if (str[counter.x++] != '\n')
			counter.y++;
	}
	return (test_relations(hashs));
}

t_form	creat_form(char valid_str[20])
{
	t_form		form;
	t_point		counter;
	int			k;
	static int	alpha = 64;

	counter = init_point();
	k = 0;
	form.alpha = (char)++alpha;
	while (counter.x < 20)
	{
		if (valid_str[counter.x] != '\n' && valid_str[counter.x] == '#')
		{
			(k == 0) ? form.p1.x = counter.y % 4 : 1 == 1;
			(k == 0) ? form.p1.y = counter.y / 4 : 1 == 1;
			(k == 1) ? form.p2.x = counter.y % 4 : 1 == 1;
			(k == 1) ? form.p2.y = counter.y / 4 : 1 == 1;
			(k == 2) ? form.p3.x = counter.y % 4 : 1 == 1;
			(k == 2) ? form.p3.y = counter.y / 4 : 1 == 1;
			(k == 3) ? form.p4.x = counter.y % 4 : 1 == 1;
			(k++ == 3) ? form.p4.y = counter.y / 4 : 1 == 1;
		}
		if (valid_str[counter.x++] != '\n')
			counter.y++;
	}
	return (form);
}
