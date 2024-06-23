NAME = push_swap

NAME_BONUS = checker

CC = cc -Wall -Wextra -Werror

INC = -I ./includes/

SRC_FILES = main.c check_sort.c check_input.c instructions1.c instructions2.c instructions3.c \
			instructions_utils.c node_utils.c sort_nano.c find_median.c sort_big.c sort_big_utils.c \
			do_best1.c do_best2.c

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

SRC_BONUS = ./src_bonus/main_bonus.c ./src_bonus/silent_bonus.c ./src/check_sort.c ./src/check_input.c ./src/instructions_utils.c ./src/node_utils.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_LIB = ./libft/libft.a

LIBFT = ./libft/

RM = rm -rf

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	@echo "$(CYAN)$(NAME)$(RESET) $(GREEN)creating...$(RESET)"
	$(CC) $(INC) $(SRC) -L./libft -lft -o $(NAME)
	@echo "$(CYAN)$(NAME)$(RESET) $(GREEN)created!$(RESET)"

bonus: $(LIBFT_LIB) $(OBJ_BONUS)
	@echo "$(CYAN)$(NAME_BONUS)$(RESET) $(GREEN)creating...$(RESET)"
	$(CC) $(INC) $(SRC_BONUS) -L./libft -lft -o $(NAME_BONUS)
	@echo "$(CYAN)$(NAME_BONUS)$(RESET) $(GREEN)created!$(RESET)"

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)Cleaning finished!$(RESET)"

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Fcleaning finished!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus


# COLORS
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
