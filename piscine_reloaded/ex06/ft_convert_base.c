/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 07:02:40 by amassnao          #+#    #+#             */
/*   Updated: 2018/08/01 14:13:04 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		fstrlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int		cal_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else
		return (nb * cal_power(nb, power - 1));
}

char	*fromdec(int nb, char *base)
{
	int		i;
	int		iter;
	char	*nbr;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	iter = nb;
	while (iter / fstrlen(base) != 0)
	{
		iter = iter / fstrlen(base);
		i++;
	}
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	nbr[0] = '-';
	while (nb / fstrlen(base) != 0)
	{
		nbr[i--] = base[nb % fstrlen(base)];
		nb = nb / fstrlen(base);
	}
	nbr[i] = base[nb % fstrlen(base)];
	return (nbr);
}

int		todec(char *nb, char *base)
{
	int		d;
	char	*ptr;

	d = 0;
	ptr = nb;
	if (*ptr == '-' || *ptr == '+')
		nb++;
	while (*nb)
	{
		if ((int)*nb >= 97 && (int)*nb <= 122)
			d = d + ((int)*nb - 87) * cal_power(fstrlen(base), fstrlen(nb) - 1);
		else if ((int)*nb >= 65 && (int)*nb <= 90)
			d = d + ((int)*nb - 55) * cal_power(fstrlen(base), fstrlen(nb) - 1);
		else
			d = d + ((int)*nb - 48) * cal_power(fstrlen(base), fstrlen(nb) - 1);
		nb++;
	}
	if (*ptr == '-')
		return (-d);
	return (d);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (fromdec(todec(nbr, base_from), base_to));
}
