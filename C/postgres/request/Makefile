# Makefile

CC		=	gcc
OBJS  =  request.o


request: $(OBJS)
	$(CC) -o $@ $^ 


%.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: clean
clean:
	rm -f *.o request

