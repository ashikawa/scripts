#include "cmp.h"

int numcmp(char *s1, char *s2)
{
   double v1, v2;

   v1 = atof(s1);
   v2 = atof(s2);

   return v1 - v2;
}

int numcmpr(char *s1, char *s2)
{
   return -1 * numcmp( s1, s2 );
}

int strcmpr(void *s1, void *s2 )
{
   return -1 * strcmp( s1, s2 );
}

