NAME = solver.a

FLAGS = -Wall -Werror -Wextra
FILES = main.c tetrominos.c 
OBJS = $(FILES:%.c=%.o)
INCLUDES = ~/42/srcs/
CC = gcc -g

all: $(NAME)


$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(FILES)
	$(CC) -c -I $(INCLUDES) $(FLAGS) $(FILES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
