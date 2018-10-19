/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:24:30 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:14:43 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		start(char const *str)
{
	int index;

	index = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t')
	{
		str++;
		index++;
	}
	return (index);
}

static int		end(char const *str)
{
	int index;

	index = 0;
	while (*str)
	{
		str++;
		index++;
	}
	str--;
	while (*str == ' ' || *str == '\n' || *str == '\t')
	{
		str--;
		index--;
	}
	return (index);
}

char			*ft_strtrim(char const *s)
{
	char	*mem;
	int		str;
	char	*p;
	int		count;

	count = end(s) - start(s);
	if (count < 0)
		count = 1;
	if (!(mem = (char *)malloc(count + 1)))
		return (NULL);
	p = mem;
	str = start(s);
	while (str < end(s))
	{
		*mem++ = s[str];
		str++;
	}
	*mem = '\0';
	return (p);
}
