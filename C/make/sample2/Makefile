# Makefile
#
# $@	ターゲット名
# $^	すべての必須項目
#

CC		=	gcc -Iinclude
OBJS	=	main.o line.o alloc.o sort.o cmp.o

vpath %.c src
vpath %.h include

main: $(OBJS)
	$(CC) -o $@ $^

#.c.o は 後方互換 GNU make は%.o: %.c
.c.o:
#%.o: %.c
#	echo $(COMPILE.c)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

main.o: line.o sort.o cmp.o
line.o: line.h alloc.o
alloc.o: alloc.h
sort.o: sort.h
cmp.o: cmp.h


# "clean" というファイルがあっても、擬似ターゲットとして扱う
.PHONY: clean
clean:
	rm -f *.o main
