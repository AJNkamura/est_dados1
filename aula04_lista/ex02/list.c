#include "list.h"

/* */
List* create () {
  return NULL;	
}

/* */
List* insert (List *l, int elem) {
  List *node = (List *)malloc(sizeof(List));
  node->data = elem;
  node->next = l;
  return node;
}

/* */
List* insert_back (List *l, int elem) {
	//crio o node antes de inserir ele em algum lugar da lista
	//reserva espaço de memoria para o novo node  e coloca o elemento 
	List* node = (List*)malloc(sizeof(List));
	node -> data = elem;
	//o elemento vai para o final da lista (dps do final eh null)
	node -> next = NULL;

	//se a lista esta vazia, retorna o node (q nesse caso eh o cabecalho)
	if (l == NULL){
		return node;	
	}
	else {
		//t e l sao ponteiros que apontam para o cabecalho
		List*  t = l;

		//t aponta para o primeiro ate o ultimo elemento
		while (t->next != NULL){
			t = t->next;
			
		}
		//t esta apontando para o ultimo elemento
		//faco t apontar para node (q criei acima ja com o NULL sendo o proximo)
		t->next = node;

	}
	//retorna l que eh o cabecalho, ou seja, me diz qual lista eh
	return l;
}


/* */
List* search (List *l, int elem) {
  if (l != NULL) {
    List *t = l;	   
    while (t != NULL) {
      if (t->data == elem) 
        return t;
       t = t->next;
    }  
  }
  return NULL;  
}

/* */
List* removek (List *l, int elem) {
  List *t = l, *p = NULL;
  while ((t != NULL) && (t->data != elem)) {
    p = t;
    t = t->next;    
  } 
  if (t == NULL) { return l; }
  if (p == NULL) { l = t->next; }
  else { p->next = t->next; }
  free (t);
  return l;
}

/* */
void print (List *l) {
  List *t;
  printf ("List: ");
  for (t = l; t != NULL; t = t->next)
    printf ("%d ", t->data);
  printf("\n");
}

/* */
void destroy (List *l) {
  if (l != NULL) {	
    List *t = l->next; 
    free (l); 
    l = t;    
  }  
}
