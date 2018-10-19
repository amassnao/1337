/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:16:05 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/06 21:33:45 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	index;
	char			*str;
	char			*strn;

	str = (char *)dst;
	strn = (char *)src;
	index = 0;
	while (index < n)
	{
		*(str + index) = (unsigned char)strn[index];
		if ((unsigned char)*(strn + index) == (unsigned char)c)
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
