NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
BONUS_DIR = bonus
INC_DIR = inc
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus
SRCS = error.c \
       init.c \
       main.c \
       normalize.c \
       operations_push.c \
       operations_rotate_1.c \
       operations_rotate_2.c \
       operations_swap.c \
       operations_utils.c \
       sort.c \
       sort_five.c \
       sort_three.c \
       sort_two.c \
       utils.c \
       validate.c \
       validate_utils.c
BONUS_SRCS = error.c \
             get_next_line.c \
			 excute_commands_1.c \
			 excute_commands_2.c \
             init.c \
             main.c \
             operations_push.c \
             operations_rotate_1.c \
             operations_rotate_2.c \
             operations_swap.c \
             operations_utils.c \
             utils_1.c \
             utils_2.c \
             validate.c \
             validate_utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
BONUS_SRCS := $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)
INCLUDES = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
