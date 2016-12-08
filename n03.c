#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
  FILE *ficheiro;
  char buffer[100];
  char *linha;
  int a,b,c;
  int i=0,j=0;
  ficheiro = fopen("input3.txt", "r");
  while (fgets(buffer, 100, ficheiro)!=NULL){
	  linha = strtok(buffer, "\n");
		a = atoi(strtok(linha, " "));
		b = atoi(strtok(NULL, " "));
		c = atoi(strtok(NULL, "\0"));
		if(((a+b)>c) && ((a+c)>b) && ((b+c)>a))
		  i++;
		else
		  j++;
	}
  fclose(ficheiro);
  printf("Quantidade Validos: %d\n", i);
  printf("Quantidade Invalidos: %d\n", j);
  return 0;
}

