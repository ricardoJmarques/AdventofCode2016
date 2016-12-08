#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parseLinha(char *linha){
  int i=0;
  int j=strlen(linha);
  int k=0;
  char matriz[2][26]={{0},{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}};
  int secID=0;
  char aux1;
  char aux2;
  char code[100];
  char room[100]={0};
  for (i=0; i<j; i++){
    if(linha[i] >='a' && linha[i] <='z'){
      matriz[0][linha[i]-'a']++;
      room[i]=linha[i];
    }
    else if(linha[i] == '-')
      room[i]=' ';
    else if(linha[i] >='0' && linha[i] <='9')
      secID = (secID * 10) + (linha[i] - '0');
    else if(linha[i] == '['){
      i++;
      while(linha[i+k] != '\0' && linha[i+k] != ']'){
          code[k] = linha[i+k];
          k++;
      }
      i=i+k;
    }
  }
  code[k]='\0';
 
  for (i = 0 ; i < 26; i++) {
    k = i;
    while ( k > 0 && matriz[0][k] > matriz[0][k-1]) {
      aux1 = matriz[0][k];
      aux2 = matriz[1][k];
      matriz[0][k] = matriz[0][k-1];
      matriz[1][k] = matriz[1][k-1];
      matriz[0][k-1] = aux1;
      matriz[1][k-1] = aux2;
      k--;
    }
  }
  matriz[1][5] = 0;
  if(strcmp(matriz[1], code) != 0){
//    printf("%s | %s\n", code, matriz[1]);
    secID = 0;
  }
  else{
    i=0;
    while(room[i] != 0){
      if (room[i] != ' ')
        room[i] = room[i]+(secID%26) > 'z' ? room[i]+(secID%26)-'z'+'a'-1 : room[i]+(secID%26);
      printf("%c", room[i]);
      i++;
    }
    printf(" | SecID: %d \n", secID);
  }
  return secID;
}

int main(){
  FILE *ficheiro;
  char buffer[1024];
  char *linha;
  int sum=0;
  ficheiro = fopen("input4.txt", "r");
  while (fgets(buffer, 100, ficheiro)!=NULL){
	  linha = strtok(buffer, "\n");
    sum += parseLinha(linha);
	}
  fclose(ficheiro);
  printf("Sum: %d\n", sum);
  return 0;
}

