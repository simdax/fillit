
#  ╓─────[ Fillit ]─[ v0.0.1 ]  
#  ║ Created by: ctrouill (ctrouill@student.42.fr)
#  ║ Created at: Tue Nov  7 14:40:48 CET 2017
#  ║ Last Edited: Tue Nov  7 14:40:48 CET 2017
#  ╙─────────────────────────────────────────── ─ ─ 

#  ╓─────[ Target ]─  
#  ╙───────────────────── ─ ─ 
NAME = fillit

#  ╓─────[ Compiler ]─  
#  ╙───────────────────── ─ ─ 
CC = gcc
CCFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L$(LIBFT) -lft

#  ╓─────[ Functions ]─  
#  ╙───────────────────── ─ ─

SRC = ft_read_map.c main.c 
LIBFT = libft/
INC = ./libft
OBJ = $(SRC:.c=.o)

vpath %.c srcs/

#  ╓─────[ Procedures ]─  
#  ╙───────────────────── ─ ─
all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) lib
	@$(CC) $(OBJ) $(CCFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "\n\033[0;32m [OK] \033[0m \033[0;33m Linking binary:\033[0m " $(NAME)

%.o : %.c
	@echo "\033[0;32m [OK] \033[0m \033[0;33m Compiling:\033[0m " $@
	@$(CC) $(CCFLAGS) -I$(INC) -I./includes  -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ)
	@/bin/rm -rf $(OBJSPATH)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo  "\033[0;31m [✗] \033[0m \033[0;33m Removed last build: \033[0m " $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

lib:
	@make -C $(LIBFT)

norme:
	norminette srcs/*.c
	norminette includes/*.h
#  ╓─────[ Call me maybe ]─  
#  ╙───────────────────── ─ ─ 
.PHONY: all lib clean fclean re
