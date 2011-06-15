/*
 * $Id: primes.c,v 0.2 2010/07/27 15:35:59 dankogai Exp dankogai $
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <math.h>

#include <stdint.h>
typedef uint32_t U32;
typedef uint64_t U64;

#include "bitmap.c"

#define SIEVEFILE "sieve32.bm"

int main(int argc, char **argv) {
    bitmap *sieve = bitmap_new(0, SIEVEFILE);
    if (!sieve){
        perror(SIEVEFILE);
        exit(errno);
    }
    U64 start = argc > 1 ? atoll(argv[1]) : 0;
    U64 size  = argc > 2 ? atoll(argv[2]) : 1000*1000*1000;
    bitmap *b = bitmap_new(size >> 1, NULL);
    bitmap_fill(b, 1);
    if (start == 0) bitmap_set(b, 0, 0);
    U64 pmax = (U64)sqrtl(start+size);
#ifdef VERBOSE
    printf("pmax = %llu\n", pmax);
#endif
    U64 p, i;
    for (p = 3; p < pmax;){
#ifdef VERBOSE
        printf("sieving %llu\r", p);
        fflush(stdout);
#endif
        for ( i = p + p - (start % p) ; i <= size ; i += p ) {
            if ((i & 1) == 0) continue; /* skip even */
            bitmap_set( b, i>>1, 0 );
        }
        for(p += 2; !bitmap_get(sieve, p>>1); p += 2); /* seek next prime */
    }

    char filename[256];
    snprintf(filename, 256, "%llu~%llu.bm", start, start+size);
#ifdef VERBOSE
    printf("saving %s\n", filename);
#endif
    bitmap_save(b, filename);
    return 0;
}
