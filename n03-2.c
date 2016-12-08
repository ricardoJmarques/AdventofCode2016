#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 917 + 817 = 1734
// 1649 + 85 = 1734

int main(){
  FILE *ficheiro;
  char buffer[100];
  char *linha;
  int a[3],b[3],c[3];
  int i=0,j=0,k=0,l=0;
  ficheiro = fopen("input3.txt", "r");
  while (fgets(buffer, 100, ficheiro)!=NULL){
    l++;
    if (k<=2){
	    linha = strtok(buffer, "\n");
		  a[k] = atoi(strtok(linha, " "));
		  b[k] = atoi(strtok(NULL, " "));
		  c[k] = atoi(strtok(NULL, "\0"));
		  k++;
		}
		else{
		  if(((a[0]+a[1])>a[2]) && ((a[0]+a[2])>a[1]) && ((a[1]+a[2])>a[0]))
		    i++;
		  else
		    j++;
		  if(((b[0]+b[1])>b[2]) && ((b[0]+b[2])>b[1]) && ((b[1]+b[2])>b[0]))
		    i++;
		  else
		    j++;
		  if(((c[0]+c[1])>c[2]) && ((c[0]+c[2])>c[1]) && ((c[1]+c[2])>c[0]))
		    i++;
		  else
		    j++;
		  k=0;
		  linha = strtok(buffer, "\n");
		  a[k] = atoi(strtok(linha, " "));
		  b[k] = atoi(strtok(NULL, " "));
		  c[k] = atoi(strtok(NULL, "\0"));
		  k++;
	  }
	}
	if(((a[0]+a[1])>a[2]) && ((a[0]+a[2])>a[1]) && ((a[1]+a[2])>a[0]))
	  i++;
	else
		j++;
  if(((b[0]+b[1])>b[2]) && ((b[0]+b[2])>b[1]) && ((b[1]+b[2])>b[0]))
	  i++;
	else
	  j++;
	if(((c[0]+c[1])>c[2]) && ((c[0]+c[2])>c[1]) && ((c[1]+c[2])>c[0]))
	  i++;
	else
	  j++;
  fclose(ficheiro);
  printf("Linhas lidas: %d\n", l);
  printf("Quantidade Validos: %d\n", i);
  printf("Quantidade Invalidos: %d\n", j);
  return 0;
}

