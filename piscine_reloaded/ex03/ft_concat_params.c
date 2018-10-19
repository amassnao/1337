/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:00:17 by amassnao          #+#    #+#             */
/*   Updated: 2018/08/01 14:19:29 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		calculeplace(char **argv)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 1;
	while (*(argv + j))
	{
		k = 0;
		while (*(*(argv + j) + k))
		{
			i++;
			k++;
		}
		j++;
	}
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = calculeplace(argv);
	str = malloc(sizeof(char) * (i + (argc - 1)));
	i = 0;
	j = 1;
	while (*(argv + j))
	{
		k = 0;
		while (*(*(argv + j) + k))
		{
			*(str + i) = *(*(argv + j) + k);
			i++;
			k++;
		}
		if (j != argc - 1)
			*(str + i++) = '\n';
		j++;
	}
	*(str + i) = '\0';
	return (str);
}
