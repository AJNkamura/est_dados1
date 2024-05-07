#include "list.h"

List* merge (List *A, List *B){
	List *C = create();
	
	List *tA = A;
	List *tB = B;
	

	if (A==NULL){
		return B;
	}
	else if (B == NULL){
		return A;
	}

	if (tA->data <= tB->data){
		C =tA;
		tA = tA->next;
	}
	else {
		C = tB;
		tB = tB -> next;
	}
	
	List *tC = C;

	while (tA != NULL && tB !=NULL){
		if (tA-> data <= tB-> data){
			tC->next = tA;
			tA = tA-> next;
		}
		else if (tB->data < tA-> data) {
			tC->next = tB;
			tB = tB-> next;
		}
		tC = tC-> next;	
	}
	while (tA != NULL){
		tC-> next = tA;
		tA = tA->next;
		tC = tC->next;
	}

	while (tB != NULL){
		tC -> next = tB;
		tB = tB-> next;
		tC = tC-> next;
	}
			
	return C;		
}


int main () {
  int k;
  List *A = NULL, *B = NULL;
  for (k = 10; k >= 0; k -= 2) 
    A = insert (A, k);
  for (k = 19; k >= 0; k -= 2) 
    B = insert (B, k);
  print (A);
  print (B);
  List *C = merge (A, B);
  print (C);
  destroy (C);
  return 0;
}
