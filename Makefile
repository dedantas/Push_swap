NAME        = push_swap
BONUS       = checker

SRCDIR      = src
INCDIR      = includes

SRC = errors.c push.c reverse.c sort_small.c \
	index.c push_swap.c rotate.c sort_utils.c \
	parsing.c radix_sort.c sort_large.c swap.c
OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

BONUS_F = checker.c
BONUS_U = errors.c push.c reverse.c sort_small.c \
	  index.c rotate.c sort_utils.c parsing.c \
	  radix_sort.c sort_large.c swap.c
BONUS_O       = $(addprefix $(SRCDIR)/, $(BONUS_F:.c=.o))
BONUS_UTILS_O = $(addprefix $(SRCDIR)/, $(BONUS_U:.c=.o))

# Libft
LIBFT_DIR = libft/
LIBFT     = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

CC  = cc -Wall -Werror -Wextra
INC = -I $(INCDIR)
RM  = rm -rf

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INC) $(LIBFT_INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(INC) $(LIBFT_INC) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo Compilation Finish

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: $(BONUS_O) $(BONUS_UTILS_O) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_O) $(BONUS_UTILS_O) $(INC) $(LIBFT_INC) -L$(LIBFT_DIR) -lft -o $(BONUS)
	@echo Bonus Compiled

clean:
	$(RM) $(OBJ) $(BONUS_O) $(BONUS_UTILS_O)
	@make clean -C $(LIBFT_DIR)
	@echo Files Cleaned

fclean: clean
	${RM} $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@echo Executables cleaned

re: fclean all

.PHONY: all clean fclean re bonus
