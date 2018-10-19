/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:19:13 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/06 17:43:01 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
		i++;
	while (*s2 != '\0' && j < nb)
	{
		*(s1 + i) = *s2;
		i++;
		s2++;
		j++;
	}
	*(s1 + i) = '\0';
	return (s1);
}