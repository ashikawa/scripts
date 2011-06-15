/*
 * $Id: mksieve32.c,v 0.1 2010/07/27 15:21:58 dankogai Exp dankogai $
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <stdint.h>
typedef uint32_t U32;
typedef uint64_t U64;

#include "bitmap.c"

int main(void) {
    bitmap *b = bitmap_new((U64)INT_MAX+1, NULL);
    bitmap_fill(b, 1);
    bitmap_set( b, 0, 0); /* 1 is not prime */
    U64 p, i;
    for (p = 3; p < USHRT_MAX ;){
        printf("sieving %llu\r", p);
        fflush(stdout);
        for ( i = p + p ; i <=  UINT_MAX ; i += p ) {
            if ((i & 1) == 0) continue; /* skip even */
            bitmap_set( b, i>>1, 0 );
        }
        for(p += 2; !bitmap_get(b, p>>1); p += 2); /* seek next prime */
    }
    char filename[]  = "sieve32.bm";
    printf("saving %s\n", filename);
    bitmap_save(b, filename);
    return 0;
}
