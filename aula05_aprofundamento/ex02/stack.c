#include "stack.h"

Stack* create () {
  return NULL;
}

void destroy (Stack *s) {
	while (s != NULL) {
        Stack *t = s->next;
        free (s);
        s = t;
  }	  
}

Stack* push (Stack *s, int elem) {
	Stack *node = (Stack*)malloc(sizeof(Stack));
	node -> data = elem;
	//como o elem vai em cima da pilha, o no aponta para a cabeça
	node -> next = s;
	return node;
}


Stack* pop (Stack *s) {
	/*Remove o elemento (free) do início da lista.*/
 	Stack* t = create;
  	if(!empty(s))
  	{
    		t = s->next;
    		free(s);//1. remover 1º nó
    		s = t;//2. atualizar a cabeça
  	}	

 	return s;
}

int get_peek (Stack *s) {
  /*Retorna a informação (data) armazenada no início da lista.*/	
	if (!empty(s)){
		return (s-> data);
	}	
}

int empty (Stack *s) {
	return (s == NULL);
}

void print (Stack *s) {
  	Stack *t;
 	printf ("List: ");
 	for (t = s; t != NULL; t = t->next){
    		printf ("%d ", t->data);
  		printf("\n");

	}
}
