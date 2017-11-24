SRC_PATH = srcs

SRC_NAME =  main.c \
            ft_read_map.c \

OBJ_PATH = obj

CPPFLAGS = -Iincludes

LDFLAGS = -Llibft

LDLIBS = -lft

NAME = a.out

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	/bin/rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	/bin/rm -fv $(NAME)

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)/*.h
