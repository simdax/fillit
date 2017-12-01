SRC_PATH = .

SRC_NAME =  ft_error.c ft_read_map.c main.c parser.c solver.c utils.c

OBJ_PATH = .

INC_PATH = .

CPPFLAGS = -I./libft

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = fillit

CC = clang
CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C ./libft/
	/bin/rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C ./libft/
	/bin/rm -fv $(NAME)

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)/*.h
