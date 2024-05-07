#include "list.h"

List* create_circular (List *head) {
	//lista vazia
	if (head == NULL){
		return NULL;
	}

	else{
	List *t = head;
		//percorre a lista ate o final
		while (t->next != NULL){
			t = t->next;
	
		}
		//ultimo aponta para cabeça e cabeca aponta para t
		t->next = head;
		head->prev = t;	
	}
	return head;	

}

int main () {
  int i;	
  int n = 4;	
  List *l = create ();
  for (i = n; i >= 0; i--) {
    l = insert_front (l, i);
  }
  print (l);
  l = create_circular(l);
  print (l);
  destroy (l);
  return 0;
} 
