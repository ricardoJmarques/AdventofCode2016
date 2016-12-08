#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define tam 8

int main(){
  FILE *ficheiro;
  char buffer[1024];
  char *linha;
  int i=0;
  int j=0;	
  char matriz[tam][26]={{0},{0}};
  char password[tam+1]={0};
  int max=0;
  int pos=0;
  ficheiro = fopen("input6.txt", "r");
  while (fgets(buffer, 100, ficheiro)!=NULL){
	  linha = strtok(buffer, "\n");
    for (i=0; i<tam; i++)
      matriz[i][linha[i]-'a']++;
	}
	for (i=0; i<tam; i++){
	  max = 100;
	  pos = 0;
	  printf("OK\n");
	  for (j=0; j<26; j++){
      if (matriz[i][j] < max){
       max  = matriz[i][j];
       pos = j;
      }
    }
    password[i]=pos+'a';
  }
  fclose(ficheiro);
  printf("%s\n", password);
  return 0;
}


