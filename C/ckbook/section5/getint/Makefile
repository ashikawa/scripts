# Makefile
CC		=	gcc
OBJS	=	main.o	getch.o	getint.o

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: getint.o 
getint.o: getch.o
