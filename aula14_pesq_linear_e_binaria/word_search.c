#include <string.h>
#include <math.h>
#include "utils.h"

/* */
int linear_search (char **words, int n, char *key) {
  //compara todos os elementos ate encontrar o que ele busca.
  //"n" eh o tamanho do vetor q abriga as palavras
  
  for (int i = 0; i < n; i++){
    //strcmp compara strings. Se forem iguais retorna 0, se word[i] > key retorna 1, e se word[i] < key retorna -1
    if(strcmp(words[i], key) == 0){
      return i;
    }
  }
}

/* */
int binary_search_iterative (char **words, int n, char *key) {
  int r = n-1;
  int l = 0;

 while (l <= r){
    int mid = (l+r)/2;
    if (strcmp(words[mid], key) == 0){
      return mid;
    }
    else if (strcmp(words[mid], key) < 0){
      l = mid + 1;
    }
    else {
      r = mid -1;
    }
   }
  return NOT_FOUND;
}


/* */
int binary_search_recursive (char **words, int r , int l, char *key) {
  if (l <= r){
    int mid = (l+r)/2;
    if (strcmp(words[mid], key) == 0){
      return mid;
    }
    else if (strcmp(words[mid], key) < 0){
      return binary_search_recursive(words, l, mid+1, key);
    }
    else {
      return binary_search_recursive(words, mid-1, r, key);
    }
   }
  else {
    return NOT_FOUND;
  }
}
/* */
int get_number_of_lines (FILE *f) {
  int n = 0;
  if (f == NULL) 
    return n; 
  while (!feof(f)) {
    char c;
    fscanf(f, "%c", &c);
    if (c == '\n') 
      n++;
  }
  rewind(f);
  return (n-1);
}

/* */
int main (int argc, char *argv[]) {
  /*if (argc < 2) { 
    printf("run: %s [word_to_search]\n", argv[0]);
    exit(1);
  }*/  
  clock_t start, end;
  double elapsed_time;
  //char *key = argv[1];
  char *key = "ACADEMICO";
  FILE *f = fopen("palavras.txt", "r"); 
  int n = get_number_of_lines(f);
  char **words = (char **)malloc(n * sizeof(char *));
  int i, index;
  for (i = 0; i < n; i++) 
    words[i] = (char *)malloc(256 * sizeof(char));
  i = 0;
  while (!feof(f)) {
    fscanf(f, "%s", words[i]);     
    i++;
  }

  /*Busca linear*/
  start = clock();
  index = linear_search (words, n, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (linear): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
 
  /*Busca binária iterativa*/
  start = clock();
  index = binary_search_iterative (words, n, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
  
  /*Busca binária recursiva*/
  start = clock();
  index = binary_search_recursive (words, 0, n-1, key);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Running time (binary): %.2f\n", elapsed_time);
  if (index >= 0) {
    printf("Key %s, found at %d\n", key, index);
  }
  else {
    printf("Element not found.\n");
  }
 
  /*Desalocando estruturas*/ 
  for (i = 0; i < n; i++) 
    free(words[i]);
  free(words);
  fclose(f);
  return 0;
}  
