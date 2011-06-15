# Makefile
# 上手く動きません

CC		=	gcc -I/usr/include/pgsql/server/ -L/usr/include/pgsql/server/
OBJS  =  clowler.o


clowler: $(OBJS) -lpq -lnsl -lcrypt
	$(CC) -o $@ $^ 


%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

clowler.o : clowler.h

.PHONY: clean
clean:
	rm -f *.o clowler

