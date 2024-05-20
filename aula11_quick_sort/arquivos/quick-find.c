#include "utils.h"

int partition (int A[], int left, int right) {
  int p = A[right];
  int i = left - 1;
  for (int j = left; j <= right-1; j++){
    if (A[j] <= p){
      i++;
      swap(A, i, j);
    }
  }
  swap(A, i+1, right);
  return i+1;
}

void quick_find(int *A, int left, int right, int k) {
  if (left <= right) {
    int p = partition(A, left, right);
    if (p == k)
        printf("O elemento eh %d\n", A[p]);
    else if (p > k)
      quick_find(A, left, p - 1, k);
    else
      quick_find(A, p + 1, right, k);
  }
}

/* */
int main () {
  int n = 8;
  int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
  print (A, n, "Input");
  quick_find (A, 0, n-1, 4);
  print (A, n, "Partial sorted");
  return 0;
}
