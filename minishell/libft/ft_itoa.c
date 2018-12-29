/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:43:36 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:01:19 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_str(int n)
{
	int	count;

	if (n >= 0 && n < 10)
		return (1);
	count = 0;
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

char			*ft_itoa(int n)
{
	char	*mem;
	int		count;

	if (!(mem = (char *)malloc(sizeof(char) * (count_str(n) + 1))))
		return (NULL);
	count = count_str(n);
	mem[count--] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0 && n < 10)
		mem[count] = n + '0';
	if (n < 0)
	{
		mem[0] = '-';
		n = -n;
	}
	while (n / 10 != 0)
	{
		mem[count] = n % 10 + '0';
		count--;
		n = n / 10;
	}
	mem[count] = n % 10 + '0';
	return (mem);
}
