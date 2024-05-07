#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main() {
    int i = 0, size = 10;
    srand(time(NULL));

    Queue *filaPar = create (size);
    Queue *filaImpar = create (size);

    while(i < size){
        int numeroSorteado = rand() % 100;
        if (numeroSorteado % 2 == 0){
            enqueue (filaPar, numeroSorteado);
        }
        else
            enqueue (filaImpar, numeroSorteado);
        i++;
    }

    print(filaPar);
    print(filaImpar);

    destroy (filaPar);
    destroy (filaImpar);

    return 0;
}
