#include "list.h"

/* */
int sum (List *l) {
  	//iterador usado para manipular a lista l sem perder o cabecalho
	// movimento i mas n movimento l
	List *i;
	int soma = 0;
	
	for (i = l; i != NULL; i = i->next){
		soma += i->data;
	}
	return soma;	
}

/* */
int main () {
  int k;
  List *l = NULL;
  for (k = 0; k <= 4; k++) 
    l = insert (l, k);
  for (k = 9; k >= 5; k--) 
    l = insert (l, k);
  print (l);
  printf("Sum = %d\n", sum(l));
  destroy (l);
  return 0;
}
