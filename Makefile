CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

NAME		:= pipex

SRC_DIR		:= src
OBJ_DIR		:= obj

SRCS		:= $(SRC_DIR)/main.c \
			   $(SRC_DIR)/init_pipex.c \
			   $(SRC_DIR)/init_pipex_utils.c \
			   $(SRC_DIR)/check_args.c \
			   $(SRC_DIR)/errors.c \
			  # $(SRC_DIR)/parse_cmds.c \
			  # $(SRC_DIR)/parse_args.c \
			  # $(SRC_DIR)/exec.c \
			  # $(SRC_DIR)/utils.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC			:= -I includes

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_INC	:= -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) $(LIBFT_INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re