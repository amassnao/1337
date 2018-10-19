/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:48:42 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:12:35 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	index;

	index = 0;
	str = (char *)malloc(size + 1);
	if (str != NULL)
	{
		while (index <= size)
			str[index++] = '\0';
		return (str);
	}
	else
		return (NULL);
}
