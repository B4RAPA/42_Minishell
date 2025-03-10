GREEN = \033[0;32m
RED = \033[31m
BLUE = \033[34m
YELLOW = \033[33m
RESET = \033[0m

NAME = minishell

CC = cc

CFLAGS = -Werror -Wall -Wextra

VALGRIND = valgrind  --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="leaks.txt"

FSANITIZE = -fsanitize=address

INCLUDE = includes

LIBFT_DIR = includes/libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

PARSING = expansion expansion_tools token parsing_main heredoc

BUILTINS = cd echo env exit export export_utils pwd unset

EXECUTION = execute main path_cmd separators execute_utils check_token signal_action signal_setup signal_restore inout_handle redir

TOOLS = free parsing fd setenv token_nav type error terminal_att

OBJ_DIR = OBJ

SRCS = $(addsuffix .c, $(addprefix srcs/parsing/, $(PARSING)))\
			$(addsuffix .c, $(addprefix srcs/tools/, $(TOOLS)))\
			$(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS)))\
			$(addsuffix .c, $(addprefix srcs/execution/, $(EXECUTION)))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -L$(LIBFT_DIR) -o $(NAME) $(OBJS) $(LIBFT) -lreadline -lncurses
	@echo "$(RESET)$(GREEN)$(NAME) ready$(RESET)."

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(BLUE)LIBFT created$(RESET)"


leaks: $(NAME)
	@$(VALGRIND) ./$(NAME)

clean:
	rm -rf $(OBJS)
	@$(MAKE) clean -sC $(LIBFT_DIR)
	@echo "$(RED) deleted objectfiles.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@echo "$(RED) $(NAME) deleted. $(RESET)"

re: fclean all

.PHONY: all clean fclean re  