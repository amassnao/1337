/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:44:02 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:10:50 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *mem;
	char *p;

	if (!(mem = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	p = mem;
	while (*s1)
		*mem++ = *s1++;
	while (*s2)
		*mem++ = *s2++;
	*mem = '\0';
	return (p);
}
