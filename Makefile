CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
RM			:= rm -f

NAME		:= pipex

SRC_DIR		:= src
OBJ_DIR		:= obj

SRCS		:= $(SRC_DIR)/main.c \
               $(SRC_DIR)/init_files.c \
               $(SRC_DIR)/pipes.c \
               $(SRC_DIR)/here_doc.c \
               $(SRC_DIR)/errors.c \
               $(SRC_DIR)/parse_cmds.c \
               $(SRC_DIR)/parse_paths.c \
               $(SRC_DIR)/exec.c \
               $(SRC_DIR)/cleanup.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC			:= -I includes

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_INC	:= -I $(LIBFT_DIR)

PRINTF_DIR	:= printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a
PRINTF_INC	:= -I $(PRINTF_DIR)

GNL_DIR		:= get_next_line
GNL_SRCS	:= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS	:= $(GNL_SRCS:.c=.o)
GNL			:= $(GNL_DIR)/get_next_line.a
GNL_INC		:= -I $(GNL_DIR)

all: $(PRINTF) $(LIBFT) $(GNL) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(GNL): $(GNL_OBJS)
	ar rcs $(GNL) $(GNL_OBJS)

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) $(LIBFT_INC) $(PRINTF_INC) $(GNL_INC) -c $< -o $@

$(NAME): $(PRINTF) $(LIBFT) $(GNL) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)

clean:
	$(RM) $(OBJS) $(GNL_OBJS)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(GNL)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re