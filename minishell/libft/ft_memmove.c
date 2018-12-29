/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:35:43 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:05:29 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	index;
	char			str[65535];
	char			*strn;
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = (char *)src;
	if (len > 65535)
		return (NULL);
	while (i++ < len)
		str[i - 1] = tmp[i - 1];
	strn = (char *)dst;
	index = 0;
	while (index < len)
	{
		strn[index] = str[index];
		index++;
	}
	return ((void *)strn);
}
