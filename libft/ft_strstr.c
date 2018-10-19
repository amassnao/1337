/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:20:43 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/07 18:25:20 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;
	char const		*ptr;

	i = 0;
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	while (i < ft_strlen(haystack) - ft_strlen(needle) + 1)
	{
		j = 0;
		while (j < ft_strlen(needle))
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
		{
			ptr = &haystack[i];
			return ((char *)ptr);
		}
		i++;
	}
	return (NULL);
}
