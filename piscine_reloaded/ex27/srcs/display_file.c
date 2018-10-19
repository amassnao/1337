/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:58:43 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/03 18:21:06 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mylib.h"

int		main(int argc, char **argv)
{
	char	buffer[10001];
	int		file;
	int		last_ps;

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		file = open(argv[1], O_RDONLY);
		last_ps = read(file, buffer, 10000);
		buffer[last_ps] = '\0';
		close(file);
		ft_putstr(buffer);
	}
	return (0);
}
