/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:46:05 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/07 18:27:09 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((unsigned char)(*s1 - *s2) == 0 && *s1 != '\0' && (int)--n > 0)
	{
		s1++;
		s2++;
	}
	if ((int)*s1 - (int)*s2 == -128)
		return (1);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
