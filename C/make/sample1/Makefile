# Makefile
#
# $@	ターゲット名
# $^	すべての必須項目
#

CC		=	gcc
OBJS	=	main.o line.o alloc.o sort.o cmp.o

main: $(OBJS)
	$(CC) -o $@ $^


.c.o:
	$(CC) -c $<

main.o: line.o sort.o cmp.o
line.o: line.h alloc.o
alloc.o: alloc.h
sort.o: sort.h
cmp.o: cmp.h


# clean ファイルがあっても、擬似ターゲットとして扱う
.PHONY: clean
clean:
	rm -f *.o main
