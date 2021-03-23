# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcossu <mcossu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 09:12:50 by mcossu            #+#    #+#              #
#    Updated: 2021/01/20 10:31:09 by mcossu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=   libftprintf.a
SRCS	=	check_fun.c \
			ft_nbrlen.c \
			ft_printf.c \
			ft_putstr.c \
			ft_putwidth.c \
			p_req_c.c \
			p_req_d.c \
			p_req_p.c \
			p_req_s.c \
			p_req_u.c \
			p_req_r.c \
			p_req_n.c \
			check_flags.c \
			get_size_num.c


OBJS	= $(SRCS:.c=.o)
CC 		= gcc
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .
LIBFT	= ./libft/libft.a
TEST	= test

$(VERBOSE).SILENT:

%.o: %.c $(LIBFT)
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): ${OBJS} $(LIBFT)
	cp	$(LIBFT) $(NAME)
	${LIBC} $(NAME) $(OBJS)


all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

clean:
	make clean -C libft
	$(RM) -f $(OBJS) $(OBJS_B)

re: fclean all

.PHONY: all bonus clean fclean re .c.o
