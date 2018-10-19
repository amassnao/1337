/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:03:10 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/03 22:54:38 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int conter;

	conter = 0;
	while (*str++)
		conter++;
	return (conter);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		conter;

	if (src == NULL)
		return (NULL);
	conter = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[conter])
	{
		str[conter] = src[conter];
		conter++;
	}
	str[conter] = '\0';
	return (str);
}
