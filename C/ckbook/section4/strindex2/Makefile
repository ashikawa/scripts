# http://www.unixuser.org/~euske/doc/makefile/#makefile
# Makefile

CC      = gcc
OBJS    = main.o getline.o

main: $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

main.o: myheader.h
getline.o: myheader.h

