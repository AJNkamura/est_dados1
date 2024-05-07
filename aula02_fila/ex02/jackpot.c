#include "queue.h"
#include <time.h>

void jackpot (int n, int r) {
	int i, n0, n1, n2;
	int size =11;
	int acertou = 0;
	srand(time(NULL));
	int n_voltas;
	int flag_acertou = 0;
	int elemento;

//declara vetor com os 3 carreteis
	Queue* vetor_carreteis[3];

//cria os 3 carreteis no vetor
	for (i = 0; i < 3; i++){
		vetor_carreteis[i] =create(size);
	}
	
//preenche cada carretel
	for (i = 1; i <= 9; i++){
		enqueue (vetor_carreteis[0], i);
		enqueue (vetor_carreteis[1], i);
		enqueue (vetor_carreteis[2], i);
	}
	while (!flag_acertou){
//sorteia o numero de voltas que cada carrosel vai dar e roda os numeros
		for (i = 0; i < 3; i++){
			n_voltas = rand() % 100;
						
//enquanto numero de voltas nao for zero "gira" e move o primeiro numero para o final
			while(n_voltas){
				elemento = dequeue (vetor_carreteis[i]);
				enqueue (vetor_carreteis[i], elemento);
				n_voltas --;
			}
		}

//na ultima vez que o carretel for mover, eu salvo o ultimo elemento removido de cada carretel para comparar e imprimir
	n0 = dequeue (vetor_carreteis[0]);
	n1 = dequeue (vetor_carreteis[1]);
	n2 = dequeue (vetor_carreteis[2]);
	
	printf ("%d %d %d \n", n0, n1, n2);
	//se acertou, muda a flag para nao continuar 
	if (n0 == n1 && n1 == n2){
		flag_acertou = 1;

	}	
	//sempre q eu der dequeue tem q dar enqueue para nao ficar faltando elemento nas filas
	enqueue(vetor_carreteis[0], n0);
	enqueue(vetor_carreteis[1], n1);
	enqueue(vetor_carreteis[2], n2);
	}

	

}

int main () {
  srand(time(NULL));	
  int n = 3;  /*número de carretéis*/ 
  int r = 10; /*sequência de números em cada carretel*/ 
  jackpot (n, r);
}

