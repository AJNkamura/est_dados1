#include "queue.h"

Queue* create () {
  return NULL;
}

//
void destroy (Queue *q) {
  while (q != NULL) {
	Queue *t = q->next;
	free (q);
  	q = t;
  }
}

int empty (Queue *q) {
	//cabeça aponta para NULL
	return (q->next == NULL);
}

Queue* enqueue (Queue *q, int elem) {
  /*Cria um elemento (malloc) e insere no final da lista.*/	
	Queue *node = (Queue*)malloc(sizeof(Queue));
	node -> data = elem;
	//o elemento vai para o final da lista (dps do final eh null)
	node -> next = NULL;

	//se a lista esta vazia, retorna o node (q nesse caso eh o cabecalho)
	if(q  == NULL){
		return node;	
	}
	else {
		//t e l sao ponteiros que apontam para o cabecalho
		Queue*  t = q;

		//t aponta para o primeiro ate o ultimo elemento
		while (t->next != NULL){
			t = t->next;
			
		}
		//t esta apontando para o ultimo elemento
		//faco t apontar para node (q criei acima ja com o NULL sendo o proximo)
		t->next = node;

	}
	//retorna l que eh o cabecalho, ou seja, me diz qual lista eh
	return q;

}

Queue* dequeue (Queue *q) {
  /*Remove o elemento (free) do início da lista. Remove a cabeca e a nova cabeca vira ->next*/	
	 if (empty(q)) {
   	 	printf ("error: queue underflow!\n");
    		exit(1);
  	}
	Queue *t = q;
	q = t->next;
}

int get_front (Queue *q) {
  /*Retorna a informação (data) armazenada no início da lista.*/	
	return (q-> data);
}

void print (Queue *q) {	
  	Queue *t;
 	printf ("List: ");
 	for (t = q; t != NULL; t = t->next){
    		printf ("%d ", t->data);
  		printf("\n");
	}
}


