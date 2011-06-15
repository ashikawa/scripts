
void swap(void *v[], int i, int j)
{
   char *temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

