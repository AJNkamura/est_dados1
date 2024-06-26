#include "utils.h"

/*Função intercala*/
void merge (int A[], int l, int m, int r, int O[], int lv) {	
  int i=l, j=m+1, k=l;
  while ((i<=m) && (j<=r)){
    if (A[i] <= A[j])
      O[k++] = A[i++];
    else
      O[k++] = A[j++];
  }
  while (i<=m)
    O[k++] = A[i++];
  while (j<=r)
    O[k++] = A[j++];
  for (int j=l; j<=r; j++)
    A[j] = O[j];
  partition_print(A, l, r, lv);
}

/*Função principal do algoritmo Merge-Sort.*/
void merge_sort (int A[], int l, int r, int O[], int lv) {
  int m = (l+r)/2;
  for (int count=0; count<lv; count ++)
    printf("    ");  
  printf("Merge-Sort(%d,%d,%d)\n", l, m, r);
  if (l<r){
    merge_sort(A, l, m, O, lv+1);
    merge_sort(A, m+1, r, O, lv+1);
    merge(A, l, m, r, O, lv+1);
  }
}
/* */
int main ( ) {
  clock_t start, end;
  double elapsed_time;
  int n = 8; /*quantidade de elementos*/
  int A[] = {5, 2, 7, 4, 8, 1, 9, 8};
  int O[n];  /*vetor auxiliar*/
  start = clock();
  print (A, n, "Input");
  merge_sort (A, 0, n-1, O, 0);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  return 0;
}

