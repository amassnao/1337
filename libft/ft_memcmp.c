/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:17:14 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:04:00 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*str;
	char			*strn;

	str = (char *)s1;
	strn = (char *)s2;
	if (n == 0)
		return (0);
	while ((unsigned char)(*str - *strn) == 0 && (int)--n > 0)
	{
		str++;
		strn++;
	}
	return ((unsigned char)*str - (unsigned char)*strn);
}
