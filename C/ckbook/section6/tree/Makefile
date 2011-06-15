# Makefile
CC		=	gcc
OBJS	=	main.o getch.o

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: getch.o 
#getch.o: getc.h

