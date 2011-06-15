#include <mecab.h>
#include <stdio.h>

#define CHECK(eval) if (! eval) { \
    fprintf (stderr, "Exception:%s\n", mecab_strerror (mecab)); \
    mecab_destroy(mecab); \
    return -1; }

int main (int argc, char **argv) {

  char input[1024] = "解析文字列";
  mecab_t *mecab;
  mecab_node_t *node;
  const char *result;
  int i;

  mecab = mecab_new (argc, argv);
  CHECK(mecab);

  result = mecab_sparse_tostr(mecab, input);
  CHECK(result)
  printf ("INPUT: %s\n", input);
  printf ("RESULT:\n%s", result);

  result = mecab_nbest_sparse_tostr (mecab, 3, input);
  CHECK(result);
  fprintf (stdout, "NBEST:\n%s", result);

  CHECK(mecab_nbest_init(mecab, input));
  for (i = 0; i < 3; ++i) {
    printf ("%d:\n%s", i, mecab_nbest_next_tostr (mecab));
  }

  node = mecab_sparse_tonode(mecab, input);
  CHECK(node);
  for (; node; node = node->next) {
    fwrite (node->surface, sizeof(char), node->length, stdout);
    printf("\t%s\n", node->feature);
  }

  node = mecab_sparse_tonode(mecab, input);
  CHECK(node);
  for (;  node; node = node->next) {
    printf("%d ", node->id);
    
    if (node->stat == MECAB_BOS_NODE)
      printf("BOS");
    else if (node->stat == MECAB_EOS_NODE)
      printf("EOS");
    else
      fwrite (node->surface, sizeof(char), node->length, stdout);

    printf(" %s %d %d %d %d %d %d %d %d %f %f %f %d\n",
	   node->feature,
	   (int)(node->surface - input),
	   (int)(node->surface - input + node->length),
	   node->rcAttr,
	   node->lcAttr,
	   node->posid,
	   (int)node->char_type,
	   (int)node->stat,
	   (int)node->isbest,
	   node->alpha,
	   node->beta,
	   node->prob,
	   node->cost);
  }

  mecab_destroy(mecab);

  return 0;
}
