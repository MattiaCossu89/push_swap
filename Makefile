SRCSPS	=

SRCSCH	= checker.c

OBJSPS	= ${SRCSPS:.c=.o}

OBJSCH	= ${SRCSCH:.c=.o}

INCSCH	= .

INCSPH	= .

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a

PS	= push_swap

CH	= checker

$(VERBOSE).SILENT:

RED		= \033[0;31m
NC		= \033[0m
GREEN	= \033[0;32m
BLUE	= \033[0;34m

%.o		: %.c
		$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I $(INCS)

all		: $(CH) $(PS)

$(PS)	: $(OBJSPS)
		make -C ./libft
		$(CC) $(OBJSPS) $(LIBFT) -I $(INCSPS) -o $(PS)
		@echo  "$(GREEN)push_swap is ready$(NC)"

$(CH)	: $(OBJSCH)
		make -C ./libft
		$(CC) $(OBJSCH) $(LIBFT)  -I $(INCSCH) -o $(CH)
		@echo  "$(GREEN)checker is ready$(NC)"


bonus	: re

test	: re
		@echo  "$(GREEN)Exec Minishell$(NC)"
		./minishell

clean	:
		make clean -C ./libft
		rm -rf $(OBJSCH) $(OBJSPS)

fclean	: clean
		make fclean -C ./libft
		rm -rf $(CH) $(PS)

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCSPS) $(SRCSCH)
	norminette -R CheckDefine $(INCSCH)/*.h $(INCSPS)/*.h

re		: fclean all

.PHONY	: all bonus clean fclean re
