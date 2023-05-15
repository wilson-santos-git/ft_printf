# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:27:53 by wteles-d          #+#    #+#              #
#    Updated: 2023/05/15 17:54:02 by wteles-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c		ft_convertion_utils.c		ft_other_utils.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

FLAGS	=	-Wall -Werror -Wextra -fPIE -g -fsanitize=address

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@
all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)	

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re