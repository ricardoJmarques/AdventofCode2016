#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//       00000000001111111111222222222233333333334444444444
//       01234567890123456789012345678901234567890123456789
//      |--------------------------------------------------|
//    0 |                                                  |
//    1 |                                                  |
//    2 |                                                  |
//    3 |                                                  |
//    4 |                                                  |
//    5 |                                                  |
//      |--------------------------------------------------|

int printDisplay(char *display){
  int i, j;
  printf("|--------------------------------------------------|\n");
  for(i=0; i<6; i++){
    printf("|");
    for(j=0; j<50; j++)
      printf("%c", display[i*50+j]);
    printf("|\n");
  }
  printf("|--------------------------------------------------|\n");
  usleep(100000);
  return 0;
}

int rotateCol(char *display, int col, int qtd){
  int i;
  char aux;
  while (qtd >0){
    aux = display[5*50+col];
    for(i=6; i>0; i--)
      display[i*50+col] = display[(i-1)*50+col];
    display[col] = aux;
    qtd--;
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printDisplay(display);
  return 0;
}

int rotateRow(char *display, int row, int qtd){
  int i;
  char aux;
  while (qtd >0){
    aux = display[row*50+49];
    for(i=49; i>=0; i--)
      display[row*50+i] = display[row*50+(i-1)];
    display[row*50] = aux;
    qtd--;
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printDisplay(display);
  return 0;
}

int rect(char *display, int tamX, int tamY){
  int i, j;
  for(i=0; i<tamY; i++)
    for(j=0; j<tamX; j++)
      display[i*50+j]='#';
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printDisplay(display);
  return 0;
}

int parseComando(char *display, char *linha){
  char *cmd;
  cmd = strtok(linha, " ");
  if (strcmp(cmd, "rect") == 0){
    int x,y;
    x = atoi(strtok(NULL, "x"));
    y = atoi(strtok(NULL, "\0"));
    rect(display, x, y);
  }
  else {
    char *rotate;
    char *aux1, *aux2;
    int pos, qtd;
    rotate = strtok(NULL, " ");
    aux1 = strtok(NULL, " ");
    aux2 = strtok(NULL, " ");
    qtd = atoi(strtok(NULL, "\0"));
    aux2 = strtok(aux1, "=");
    pos = atoi(strtok(NULL, "\0"));
    if (strcmp(rotate, "row") == 0)
      rotateRow(display, pos, qtd);
    else
      rotateCol(display, pos, qtd);
  }
  return 0;
}

int main(){
  int i=0;
  int sum=0;
  char display[6*50];
  for(i=0; i< 300; i++)
    display[i] = ' ';
  FILE *ficheiro;
  char buffer[1024];
  char *linha;
  ficheiro = fopen("input8.txt", "r");
  while (fgets(buffer, 1024, ficheiro)!=NULL){
	  linha = strtok(buffer, "\n");
    parseComando(display, linha);
//    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//    printDisplay(display);
//    usleep(100000);
	}
  fclose(ficheiro);
  for(i=0; i< 300; i++)
    if(display[i] == '#')
      sum++;
   printf("|-------- Pixels On: %3d | Pixels Off: %3d --------|\n", sum, 300-sum);
   printf("|--------------------------------------------------|\n");
  return 0;
}
