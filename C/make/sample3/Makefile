# Makefile
#
# $@	ターゲット名
# $^	すべての必須項目
#

CC		=	gcc -Iinclude
OBJS	=	main.o line.o alloc.o cmp.o mysort.o swap.o

vpath %.c src
vpath %.h include

main: $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c $<

main.o: main.c
line.o: line.h line.c alloc.h
alloc.o: alloc.h alloc.c
mysort.o: mysort.h mysort.c swap.h
cmp.o: cmp.h cmp.c
swap.o: swap.c swap.h

# "clean" というファイルがあっても、擬似ターゲットとして扱う
.PHONY: clean
clean:
	rm -f *.o main
