#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long int descomprime(char *linha){ 
  int i=0,j=0;
  long int size = 0;
//  int add=0;
  int tam=0;
  int repeat=0;
  char aux[100]={0};
  char *buffer;
  while(linha[i] != 0){
    if(linha[i] != '('){
      if(linha[i] != ' ')
        size++;
      i++;
    }
    else {
      i++;
      j=0;
      while(linha[i] != ')'){
        aux[j] = linha[i];
        i++;
        j++;
      }
      i++;
      tam = atoi(strtok(aux, "x"));
      repeat = atoi(strtok(NULL, "\0"));
      buffer = (char*)malloc(tam+1);
      memcpy(buffer, &linha[i], tam);
      buffer[tam] = '\0';
      
      size += repeat * descomprime(buffer);
      i+=tam;
      for(j=0; j<100; j++)
        aux[j] = 0;
	  }
	}
	return size;
}

int main(){
  FILE *ficheiro;
  char buffer[1000000]={0};
  char *linha;
  long int size = 0;
  ficheiro = fopen("input9.txt", "r");
  while (fgets(buffer, 1000000, ficheiro)!=NULL){
    linha = strtok(buffer, "\n");
	  size += descomprime(linha);
	}
  fclose(ficheiro);
  printf("Caracteres: %ld\n", size);
  return 0;
}
