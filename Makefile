NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = av_control.c \
      control.c \
      mini_sort.c \
      ps_action.c \
      ps_action_2.c \
      push_swap.c \
      radix.c \
      split.c \
      utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "🚀 🔹 Created object file: $@"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) && echo "🏆 🔸 Executable $(NAME) successfully created!"

clean:
	@$(RM) $(OBJ) && echo "🧹 ✨ Object files have been cleaned up!"

fclean: clean
	@$(RM) $(NAME) && echo "💥 🗑️ Removed executable: $(NAME)"

re: fclean all
	@echo "🔄 🔧 Project rebuilt successfully!"

.PHONY: all clean fclean re