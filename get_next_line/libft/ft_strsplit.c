/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:02:51 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/09 22:22:14 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(char const *s, char c)
{
	int start;
	int	end;
	int index;
	int count;

	start = 0;
	index = 0;
	count = 1;
	while (s[index])
	{
		if (s[index] == c)
		{
			end = index;
			if (end - start > 0)
				count++;
			start = index + 1;
		}
		index++;
	}
	return (count);
}

static char		*allocat_str(char const *s, int start, int end)
{
	char *mem;
	char *p;

	mem = (char *)malloc(sizeof(char) * (end - start + 1));
	if (mem == NULL)
		return (NULL);
	p = mem;
	while (start < end)
	{
		*mem++ = s[start];
		start++;
	}
	*mem = '\0';
	return (p);
}

static int		allchar(const char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		start;
	int		end;
	int		index;
	int		count;
	char	**words;

	start = 0;
	index = 0;
	count = 0;
	if (!(words = (char **)malloc(sizeof(char *) * word_count(s, c))))
		return (NULL);
	while (s[index++])
	{
		if (s[index - 1] == c)
		{
			end = index - 1;
			if (end - start > 0)
				words[count++] = allocat_str(s, start, end);
			start = index;
		}
	}
	if ((s[start] && s[start] != c) || (words[0] == NULL && allchar(s, c) != 1))
		words[count++] = allocat_str(s, start, ft_strlen(s));
	words[count] = NULL;
	return (words);
}
