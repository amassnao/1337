/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:02:51 by amassnao          #+#    #+#             */
/*   Updated: 2018/12/24 22:13:37 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int conter;

	conter = 0;
	while (*s)
	{
		if (*s != c)
		{
			conter++;
			while (*s)
				if (*s != c)
					s++;
				else
					break ;
			continue;
		}
		s++;
	}
	return (conter);
}

static char		*word_place(const char *s, char c)
{
	int			conter;
	char		*word;
	const char	*p;
	int			i;

	p = s;
	conter = 0;
	while (*s && *(s++) != c)
		conter++;
	word = malloc(sizeof(char) * (conter + 1));
	i = 0;
	while (*p)
		if (*p != c)
			word[i++] = *(p++);
		else
			break ;
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		conter;

	words = malloc(sizeof(char *) * (word_count(s, c) + 1));
	conter = 0;
	while (*s)
	{
		if (*s != c)
		{
			words[conter++] = word_place(s, c);
			while (*s)
				if (*s != c)
					s++;
				else
					break ;
			continue;
		}
		s++;
	}
	words[conter] = NULL;
	return (words);
}
