SRCSPS	=	push_swap.c \
			op/push.c \
			op/read.c \
			op/rev_rotate.c \
			op/rotate.c \
			op/swap.c \
			sort/compute_sorting.c \
			sort/find_fun.c \
			sort/littlesort.c \
			sort/set_stacks.c \
			sort/sort.c \
			utils/exit.c \
			utils/fill_input.c \
			utils/fill_input1.c \
			utils/min_n_max.c \
			utils/sort_utils.c

SRCSCH	=	checker.c \
			op/push.c \
			op/read.c \
			op/rev_rotate.c \
			op/rotate.c \
			op/swap.c \
			utils/exit.c \
			utils/fill_input.c \
			utils/fill_input1.c \
			utils/print.c \
			utils/print1.c

OBJSPS	= ${SRCSPS:.c=.o}

OBJSCH	= ${SRCSCH:.c=.o}

INCSCH	= includes

INCSPH	= .

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a

LIBPF	= ./ft_printf/libftprintf.a

PS	= push_swap

CH	= checker

$(VERBOSE).SILENT:

RED		= \033[0;31m
NC		= \033[0m
GREEN	= \033[0;32m
BLUE	= \033[0;34m

%.o		: %.c
		$(CC) $(FLAGS) -I $(INCSCH) -c $< -o ${<:.c=.o}

all		: $(CH) $(PS)

$(PS)	: $(OBJSPS)
		make -C ./libft
		$(CC) $(OBJSPS) $(LIBFT) -I $(INCSCH) -o $(PS)
		@echo  "$(GREEN)push_swap is ready$(NC)"

$(CH)	: $(OBJSCH)
		make -C ./libft
		make -C ./ft_printf
		$(CC) $(OBJSCH) $(LIBFT) $(LIBPF) -I $(INCSCH) -o $(CH)
		@echo  "$(GREEN)checker is ready$(NC)"


bonus	: re

clean	:
		make clean -C ./libft
		make clean -C ./ft_printf
		rm -rf $(OBJSCH) $(OBJSPS)

fclean	: clean
		make fclean -C ./libft
		make fclean -C ./ft_printf
		rm -rf $(CH) $(PS)

norme:
	make norme -C ./libft
	make norme -C ./ft_printf
	norminette -R CheckForbiddenSourceHeader $(SRCSPS) $(SRCSCH)
	norminette -R CheckDefine $(INCSCH)/*.h

re		: fclean all

.PHONY	: all bonus clean fclean re
