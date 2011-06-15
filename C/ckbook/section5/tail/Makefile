# Makefile
CC		=	gcc
OBJS	=	main.o line.o alloc.o stoi.o

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: line.o stoi.o
line.o: line.h alloc.o
alloc.o: alloc.h
stoi.o: stoi.h
