/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite_whitespaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:59:04 by amassnao          #+#    #+#             */
/*   Updated: 2018/08/01 20:16:06 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_space(char str)
{
	if (str == ' ' ||
			str == '\t' ||
			str == '\n')
		return (1);
	return (0);
}

int		calc_words(char *str)
{
	int conter;

	conter = 0;
	while (*str)
	{
		if (!check_space(*str))
		{
			conter++;
			while (!check_space(*str) && *str)
				str++;
		}
		else
			str++;
	}
	return (conter);
}

int		ft_strlen_extend(char *str)
{
	int i;

	i = 0;
	while (!check_space(*str) && *(str++))
		i++;
	return (i);
}

char	*allocstr(char *str)
{
	char *strloc;
	char *pstrloc;

	strloc = (char *)malloc(sizeof(char) * (ft_strlen_extend(str) + 1));
	pstrloc = strloc;
	while (ft_strlen_extend(str))
		*(strloc++) = *(str++);
	*strloc = '\0';
	return (pstrloc);
}

char	**ft_split_whitespaces(char *str)
{
	char	**words;
	int		index;

	index = 0;
	words = (char **)malloc(sizeof(char *) * (calc_words(str) + 1));
	while (*str)
	{
		if (!check_space(*str))
		{
			*(words + index++) = allocstr(str);
			while (!check_space(*str) && *str)
				str++;
		}
		else
			str++;
	}
	*(words + index) = 0;
	return (words);
}
