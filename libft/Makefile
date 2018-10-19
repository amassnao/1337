# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassnao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 17:08:28 by amassnao          #+#    #+#              #
#    Updated: 2018/10/06 18:26:54 by amassnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

$(NAME) :
	gcc -c -Wall -Wextra -Werror *.c *.h
	ar rc $(NAME) *.o
all : $(NAME)

clean :
	rm -f *.o 
	rm -f *.gch
fclean : clean
	rm -f $(NAME)
re : fclean $(NAME)
