# Makefile
# 上手く動きません

CC		=	gcc -I/usr/include/pgsql/server/ -L/usr/include/pgsql/server/
OBJS  =  sample.o


sample: $(OBJS) -lpq -lnsl -lcrypt
	$(CC) -o $@ $^ 


%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

sample.o : sample.h

.PHONY: clean
clean:
	rm -f *.o sample

