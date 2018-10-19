/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 04:24:46 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 21:59:00 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			calculate(const char *str, int i, int n, double base)
{
	double	a;

	a = 0;
	while (i < n)
	{
		a = a + ((int)*(str + i) - 48) * base;
		base = base / 10;
		i++;
	}
	if (a < -2147483648)
		return (0);
	else if (a > 2147483648)
		return (-1);
	return (a);
}

static char const	*clean(const char *str, int *s)
{
	*s = 1;
	while (*str == '\r' || *str == '\v' || *str == '\f'
			|| *str == '\t' || *str == '\n' || *str == ' ')
		str++;
	return (str);
}

int					ft_atoi(const char *str)
{
	double	base;
	int		i;
	int		s;

	i = 0;
	base = 1;
	str = clean(str, &s);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '-' && i == 0)
		{
			base = -1;
			s = 2;
		}
		else if (*(str + i) == '+' && i == 0)
			s = 2;
		else if ((int)*(str + i) >= 48 && (int)*(str + i) <= 57 && i < s)
			base = base * 1;
		else if ((int)*(str + i) >= 48 && (int)*(str + i) <= 57 && i >= s)
			base = base * 10;
		else
			break ;
		i = i + 1;
	}
	return (calculate(str, s - 1, i, base));
}
