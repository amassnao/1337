/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:21:37 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/03 21:42:28 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;
	int i;

	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
