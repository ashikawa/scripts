
CC    := gcc -Iinclude
OBJS  := mecab.o


main: $(OBJS)
	gcc -O2 `mecab-config --cflags` $^ -o $@ `mecab-config --libs`
.c.o:
	$(CC) -c $<

# "clean" というファイルがあっても、擬似ターゲットとして扱う
.PHONY: clean
clean:
	@rm -f *.o main
	@echo clean end

