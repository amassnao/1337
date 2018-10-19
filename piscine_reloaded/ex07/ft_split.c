/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:23:21 by amassnao          #+#    #+#             */
/*   Updated: 2018/08/02 15:58:41 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		calcule_word(char *str, char *charset)
{
	int i;

	i = 0;
	while (!compare(str++, charset) && *(str - 1))
		i++;
	return (i);
}

char	*allocstr(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (calcule_word(str, charset) + 1));
	while (calcule_word(str, charset))
		*(word + i++) = *(str++);
	*(word + i) = '\0';
	return (word);
}

int		calcule_words(char *str, char *charset)
{
	int conter;

	conter = 0;
	while (*str)
	{
		if (compare(str, charset))
			conter++;
		str++;
	}
	return (conter);
}

char	**fixarray(char **array)
{
	int		conter;
	char	**new_array;
	char	**root;
	char	**roott;
	int		gconter;

	conter = 0;
	root = array;
	gconter = 0;
	while (*array != 0)
	{
		if (!isempty(*(array++)))
			conter++;
		gconter++;
	}
	new_array = malloc(sizeof(char*) * (conter + 1));
	roott = new_array;
	while (gconter--)
		if (!isempty(*(root++)))
			*(new_array++) = *(root - 1);
	*(new_array) = 0;
	return (roott);
}

char	**ft_split(char *str, char *charset)
{
	char	**data;
	int		i;

	i = 0;
	data = (char **)malloc(sizeof(char *) * (calcule_words(str, charset) + 2));
	while (*str)
	{
		if (!compare(str, charset))
		{
			*(data + i++) = allocstr(str, charset);
			while (!compare(str, charset) && *str)
				str++;
		}
		else
			str = str + ft_strlen(charset);
	}
	*(data + i) = 0;
	return (fixarray(data));
}
