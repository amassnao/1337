/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:15:34 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/03 14:21:27 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	while (nb > 0)
		factorial = factorial * nb--;
	return (factorial);
}
