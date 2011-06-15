# Makefile
CC		=	gcc
OBJS	=	main.o line.o alloc.o sort.o cmp.o

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: line.o sort.o cmp.o
line.o: line.h alloc.o
alloc.o: alloc.h
sort.o: sort.h
cmp.o: cmp.h
