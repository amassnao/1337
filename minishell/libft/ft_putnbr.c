/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 21:09:22 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/06 17:07:00 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char ch;

	if (nb == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10 && nb != -2147483648)
	{
		ch = nb + '0';
		ft_putchar(ch);
	}
	else if (nb != -2147483648)
	{
		ft_putnbr(nb / 10);
		ch = nb % 10 + '0';
		ft_putchar(ch);
	}
}
