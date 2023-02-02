NAME = push_swap

SRCS = 	main.c \
		parcing/pars.c \
		parcing/utils.c \
		parcing/utils2.c \
		parcing/utils3.c \
		parcing/ft_split.c \
		init_pile_a/def_pile_a.c \
		init_pile_a/utils.c \
		move/move.c \
		move/move2.c \
		move/move3.c \
		algo/lis.c \
		algo/lis2.c \
		algo/daron.c \
		algo/tri.c \
		algo/tri2.c 

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

CC = gcc -Wall -Werror -Wextra

RM = rm -f

HEADER = push_swap.h
CFLAGS = -g3 

OBJS = ${SRCS:.c=.o}


all:	$(NAME)

$(NAME):  $(MLX) $(OBJS)
		${CC} $(OBJS) -o $(NAME) 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

clean:
	@$(RM) ${OBJS}
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN) ./_push_swap have been deleted$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"

.PHONY: all clean fclean re 