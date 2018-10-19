/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassnao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:11:50 by amassnao          #+#    #+#             */
/*   Updated: 2018/10/16 22:05:10 by amassnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 21101

typedef struct	s_data
{
	int				fd;
	int				pointer;
	int				last_char;
	char			*buffer;
	struct s_data	*next;
}				t_data;

int				get_next_line(const int fd, char **line);
#endif
