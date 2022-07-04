# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelarose <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 12:31:59 by jelarose          #+#    #+#              #
#    Updated: 2019/12/15 23:41:15 by jelarose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=  	ft_printf.c \
		parsing.c \
		print_conv.c \
		print_conv2.c \
		utils.c \
		utils2.c \

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

all:		$(NAME) 

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) ft_printf.h
			ar rc $(NAME) $(OBJS)

clean:
			rm -f  $(OBJS)

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
