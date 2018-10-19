# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassnao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 15:41:12 by amassnao          #+#    #+#              #
#    Updated: 2018/10/03 21:11:59 by amassnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	gcc -c -Wall -Wextra -Werror srcs/*
	ar rc libft.a *.o
clean :
	rm -f *.o
fclean : clean
	rm libft.a
re : fclean all
