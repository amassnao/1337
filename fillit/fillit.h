/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:11:42 by zchatoua          #+#    #+#             */
/*   Updated: 2018/10/24 22:37:14 by zchatoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_hash
{
	int			i;
	int			j;
	int			relation;
}				t_hash;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_form
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		p4;
	t_point		left;
	int			width;
	int			height;
	char		alpha;
}				t_form;

char			**creat_plan(t_point size);
char			**add_to_plan(char **plan, t_form form, t_point coord);
char			**remove_from_plan(char **plan, t_form form, t_point coord);
char			**copy_plan(char **plan, char **plan_tmp, t_point size);
void			affiche_plan(char **plan, t_point size);

t_form			creat_form(char valid_str[20]);
void			init_form(t_form *tetro);
t_point			get_free_place(char **plan, t_form form,
		t_point start, t_point size);

int				is_valid_str(char str[20]);
int				check_availibity(char **plan, t_form form,
		t_point size, t_point coord);
int				get_width(t_point p1, t_point p2, t_point p3, t_point p4);
int				get_height(t_point p1, t_point p2, t_point p3, t_point p4);
int				get_size(t_form forms[27], t_point start);
int				get_rest(char **plan, t_point place, t_point size);
t_point			get_left(t_form elem);
t_point			init_point();

int				optimize(t_point *place, t_point size,
		t_point start[2], t_point p);
int				solve_forms(char **plan, t_form forms[27],
		t_point start[2], t_point size);

#endif
