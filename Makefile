NAME = fillit

FLAGS = -Wall -Werror -Wextra
FILES = main.c tetrominos.c 
OBJS = $(FILES:%.c=%.o)
INCLUDES = ~/42/srcs/
CC = gcc -g

all: $(NAME)

$(OBJS): $(FILES)
	$(CC) -c -I $(INCLUDES) $(FLAGS) $(FILES)

$(NAME): $(OBJS)
	$(CC) -lft $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
