NAME = fillit

FLAGS = -Wall -Werror -Wextra
FILES = 
OBJS = $(FILES:%.c=%.o)
INCLUDES = ~/42/42/libft/
CC = gcc

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
