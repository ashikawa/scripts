/*
 * $Id: bitmap.c,v 0.2 2010/07/27 15:27:02 dankogai Exp dankogai $
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef struct {
    int    fd;
    size_t size;
    char  *map;
} bitmap;

bitmap *bitmap_free(bitmap *b){
    if (b){
        if (b->map) {
            if (b->fd){
                munmap(b->map, b->size);
                close(b->fd);
            }else{
                free(b->map);
            }
        }
        free(b);
    }
    return (bitmap *)NULL;
}

bitmap *bitmap_new(size_t size, const char *filename){
    bitmap *b = (bitmap *)malloc(sizeof(bitmap));
    struct stat st;
    if (!b) return (bitmap *)NULL;
    if (filename){
        b->fd = open(filename, 
                     size ? O_RDWR|O_CREAT : O_RDONLY, 
                     size ? (mode_t)0644   : (mode_t)0444);
        if (b->fd == -1) {
            perror(filename);
            return bitmap_free(b);
        }
        if (size){
            if (ftruncate(b->fd, size >> 3) == -1){
                perror(filename);
                return bitmap_free(b);
            }
            b->map = (char *)mmap(0, size >> 3, PROT_READ|PROT_WRITE,
                                  MAP_SHARED, b->fd, 0);

        }
        else{
            fstat(b->fd, &st);
            size = st.st_size << 3;
            b->map = (char *)mmap(0, size >> 3, PROT_READ, 
                                  MAP_PRIVATE, b->fd, 0);
        }
        if (b->map == MAP_FAILED) return bitmap_free(b);
    }
    else{
        if (!size) return (bitmap *)NULL;
        b->map = (char *)malloc(size >> 3);
        if (!b->map) return bitmap_free(b);
        b->fd = 0;
    }
    b->size = size;
    return b;
}

int bitmap_save(bitmap *b, const char *filename){
    int ok = 0, fd = open(filename, O_RDWR|O_CREAT|O_TRUNC, (mode_t)0644);
    if (fd != -1){
        if (write(fd, b->map, (b->size >> 3)) != -1) ok = 1;
    }
    if (!ok) perror(filename);
    close(fd);
    return ok;
}

void bitmap_fill(bitmap *b, int val){
    size_t i;
    for (i = 0; i < (b->size >> 3); i++) b->map[i] = val ? 0xff : 0;
}

static const int bits[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

inline int bitmap_set(bitmap *b, size_t where, int val){
    if (val) b->map[where >> 3] |=  bits[where & 7];
    else b->map[where >> 3] &= ~bits[where & 7];
    return val;
}

inline int bitmap_get(bitmap *b, size_t where){
    return !!(b->map[where >> 3] & bits[where & 7]);
}

#ifdef TEST
#include <errno.h>
int main (int argc, char **argv){
    bitmap *b = bitmap_new(4096, (argc > 1 ? argv[1] : NULL));
    if (!b) return errno;
    bitmap_set(b, 0, 1);
    printf("%d\n", bitmap_get(b, 0));
    bitmap_free(b);
    return 0;
}
#endif
