/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 16:01:03 by amassnao          #+#    #+#             */
/*   Updated: 2018/08/02 16:01:52 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compare(char *str, char *charset)
{
	while (*charset)
	{
		if (!*str)
			return (0);
		if (*charset++ != *str++)
			return (0);
	}
	return (1);
}

int		isempty(char *str)
{
	while (*(str++))
		if (*(str - 1) != ' ')
			return (0);
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
