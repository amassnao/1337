/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:41:43 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/07 18:24:29 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int index;
	int p;

	index = 0;
	p = -1;
	while (s[index])
	{
		if (s[index] == (unsigned char)c)
			p = index;
		index++;
	}
	if (s[index] == c)
		return ((char *)s + index);
	if (p != -1)
		return ((char *)s + p);
	return (NULL);
}
