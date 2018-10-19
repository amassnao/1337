/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:08:38 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/07 18:35:00 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	char	*p;
	size_t	index;

	mem = (char *)malloc(len + 1);
	if (mem == NULL)
		return (NULL);
	p = mem;
	index = 0;
	while (index++ < len && s[start])
	{
		*mem = s[start++];
		mem++;
	}
	*mem = '\0';
	return (p);
}
