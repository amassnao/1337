/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:03:57 by amassnao          #+#    #+#             */
/*   Updated: 2018/07/28 13:53:08 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dst + i) = '\0';
		i++;
	}
	return (dst);
}
