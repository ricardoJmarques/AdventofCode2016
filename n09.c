#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int descomprime(char *linha){ 
  int i=0,j=0;
  int size = 0;
  int tam;
  int repeat;
  char aux[100];
  while(linha[i] != '\0'){
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
      size += (tam*repeat);
      i += tam;
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
  int size = 0;
  ficheiro = fopen("input9.txt", "r");
  while (fgets(buffer, 1000000, ficheiro)!=NULL){
    linha = strtok(buffer, "\n");
	  size += descomprime(linha);
	}
  fclose(ficheiro);
  printf("Caracteres: %d\n", size);
  return 0;
}
