/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:05:30 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/06 17:48:01 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	index;
	char			*str;
	char			*strn;

	str = (char *)dst;
	strn = (char *)src;
	index = 0;
	while (index < n)
	{
		str[index] = strn[index];
		index++;
	}
	return ((void *)dst);
}
