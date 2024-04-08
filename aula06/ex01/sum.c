#include "list.h"

/* */
int sum (List *l) {
	//Comeco com o valor da cebeca e somo o proximo ao chamar a funcao novamente 
	if (l != NULL) {
		return l->data + sum(l->next);

	}
	else
		return 0;
}

/* */
int main () {
  List *l = NULL;
  int k;
  for (k = 5; k <= 9; k++) {
    l = insert_back (l, k);
  }
  for (k = 4; k >= 0; k--) {
    l = insert_back (l, k);
  }
  printf("Lista = ");
  print (l);
  printf("\n");
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
