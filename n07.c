#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parseLinha(char *linha){
  int i=0;
  int j=0;
  int k=0;
  int l=0;
  int flag = 0;
  int stop = 0;
  char matriz[10][1024]={{0},{0}};  
  while(linha[i]!=0){
    if(linha[i]=='[' || linha[i]==']'){
      j++;
      k=0;
    }
    else {
      matriz[j][k]=linha[i];
      k++;
    }
    i++;
  }
  for(i=0; !stop && i<=j; i++){
    l = (int)(strlen(matriz[i])-3);
    for(k=0; !stop && k<l; k++)
      if(matriz[i][k]!=matriz[i][k+1] && matriz[i][k] == matriz[i][k+3] && matriz[i][k+1] == matriz[i][k+2]){
        if(i%2==0){
          flag = 1;
          printf("%c%c%c%c - string # %d: %s - posicao: %d - \n", matriz[i][k], matriz[i][k+1], matriz[i][k+2], matriz[i][k+3], i, matriz[i], k);
        }
        else{
          flag = 0;
          stop = 1;
        }
      }
  }
  return flag;
}

int main(){
  FILE *ficheiro;
  char buffer[1024];
  char *linha;
  int sum=0;
  ficheiro = fopen("input7.txt", "r");
  while (fgets(buffer, 1024, ficheiro)!=NULL){
	  linha = strtok(buffer, "\n");
    sum += parseLinha(linha);
	}
  fclose(ficheiro);
  printf("Sum: %d\n", sum);
  return 0;
}

