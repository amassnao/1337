/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:24:22 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:11:24 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	index;
	char			*ss;

	index = 0;
	if (!(ss = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[index])
	{
		ss[index] = (*f)(s[index]);
		index++;
	}
	ss[index] = '\0';
	return (ss);
}
