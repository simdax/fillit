all:
	gcc -g main.c parser/parser.a solver/solver.a libft/libft.a -o fillit

clean:
	rm -f *o
fclean: clean
	rm -f fillit
re:	fclean
	make all
