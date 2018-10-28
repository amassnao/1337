# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 22:54:03 by zchatoua          #+#    #+#              #
#    Updated: 2018/10/24 23:07:01 by zchatoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FLAGS = -Wall -Werror -Wextra
NAME = fillit
all : $(NAME)

$(NAME) : *.c
	gcc $(FLAGS) -c fillit.c  get.c isvalid.c map.c utile.c libft/*.c -I.
	gcc $(FLAGS) main.c *.o -o $@
clean :
	rm -f *.o
fclean : clean
	rm -f fillit
re : fclean all
