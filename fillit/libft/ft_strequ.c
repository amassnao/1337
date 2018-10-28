/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:36:31 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/06 07:51:14 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 - *s2 != 0)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
