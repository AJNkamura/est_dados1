#include "utils.h"

/* */
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

/* */
int random_partition (int A[], int left, int right) {
	//sorteio aleatorio da posicao pivo tal que left <= p <= right
	int p = rand()%(right-left+1)+500;
	swap(A, p, right);
	
	//troco o pivo com o n aleatorio sorteado
	return partition (A, left, right);
}

/* */
void quick_sort (int *A, int left, int right) {
	if (left<right){
    		int p = partition(A, left, right);
    		quick_sort(A, left, p-1);
    		quick_sort(A, p+1, right);
	}
}
	/* */
int main (int argc, char *argv[]) {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;
  int n = 1000; /*Altere para 100, 1000, 10 mil, 1 milhao elementos!*/
  int range = 10; /*intervalo de valores sorteados*/
  int *A = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++) {
    A[i] = rand() % (n+1); /*valores aleatórios*/
    //A[i] = i; /*ordem crescente*/
    //A[i] = n-i; /*ordem descrente*/
    //A[i] = 0; /*iguais*/
  }  

  start = clock();
  print (A, n, "Input");
  quick_sort (A, 0, n-1);
  print (A, n, "Sorted");
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time: %.2f\n", elapsed_time);
  if (!check(A, n, TRUE)) {
    printf("Error: non-ascending order!\n");
  }
  free (A);
  return 0;
}

