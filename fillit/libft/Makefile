HEADER	= libft.h
CFLAG	= -Wall -Wextra -Werror
NAME	= libft.a

all : $(NAME)

$(NAME) :	object
	@ar rc $@ *.o \
	&& ranlib $(NAME) 

object : 
	@gcc $(CFLAG) -c *.c -I$(HEADER) 

clean :
	@rm -rf *.o
fclean : clean
	@rm -rf $(NAME)
re : fclean all
