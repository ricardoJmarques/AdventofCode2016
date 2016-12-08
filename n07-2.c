#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parseLinha(char *linha){
  int i=0;
  int j=0;
  int k=0;
  int l=0;
  int m=0;
  int n=0;
  int o=0;
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
  for(i=0; !stop && i<=j; i+=2){
    l = (int)(strlen(matriz[i])-2);
    for(k=0; k<l; k++)
      if(matriz[i][k]!=matriz[i][k+1] && matriz[i][k] == matriz[i][k+2])
        for(m=1; m<=j; m+=2){
          n = (int)(strlen(matriz[m])-2);
          for (o=0; o<=n; o++)
            if(matriz[m][o]!=matriz[m][o+1] && matriz[m][o] == matriz[m][o+2] && matriz[m][o] == matriz[i][k+1] && matriz[m][o+1] == matriz[i][k])
              flag = 1;
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

