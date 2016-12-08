#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int actualizaPosicao(int *x, int *y, char ori, char dir, int dist){
//  printf("Ori: %c | Dir: %c | dist: %d | Xi: %d | Yi: %d | ", ori, dir, dist, *x, *y);
	if(ori=='N')
	  *x += dist;
	else if(ori=='S')
	  *x -= dist;
	else if(ori=='E')
	  *y -= dist;
	else
	  *y += dist;
//	printf("Xf: %d | Yf: %d\n", *x, *y);
	return 0;
}

char mudaDireccao(char ori, char dir){
	if(ori=='N'){
		if(dir=='R')
			ori='O';
	  else
	    ori='E';
	}
	else if(ori=='S'){
		if(dir=='R')
			ori='E';
	  else
	    ori='O';
	}
	else if(ori=='E'){
		if(dir=='R')
			ori='N';
	  else
	    ori='S';
	}
	else {
		if(dir=='R')
			ori='S';
	  else
	    ori='N';
	}
	return ori;
}

int main(){
	char input[] = {"R1, L3, R5, R5, R5, L4, R5, R1, R2, L1, L1, R5, R1, L3, L5, L2, R4, L1, R4, R5, L3, R5, L1, R3, L5, R1, L2, R1, L5, L1, R1, R4, R1, L1, L3, R3, R5, L3, R4, L4, R5, L5, L1, L2, R4, R3, R3, L185, R3, R4, L5, L4, R48, R1, R2, L1, R1, L4, L4, R77, R5, L2, R192, R2, R5, L4, L5, L3, R2, L4, R1, L5, R5, R4, R1, R2, L3, R4, R4, L2, L4, L3, R5, R4, L2, L1, L3, R1, R5, R5, R2, L5, L2, L3, L4, R2, R1, L4, L1, R1, R5, R3, R3, R4, L1, L4, R1, L2, R3, L3, L2, L1, L2, L2, L1, L2, R3, R1, L4, R1, L1, L4, R1, L2, L5, R3, L5, L2, L2, L3, R1, L4, R1, R1, R2, L1, L4, L4, R2, R2, R2, R2, R5, R1, L1, L4, L5, R2, R4, L3, L5, R2, R3, L4, L1, R2, R3, R5, L2, L3, R3, R1, R3\0"};
	int x=0;
  int y=0;
  char ori='N';
  char dir=0;
  int dist=0;
	char *s;
	int i=1;
	s = strtok(input, ",");
	dir = s[0];
	while (s[i]!=0 && i<10){
	  dist = (dist * 10)+(s[i]-'0');
	  i++;
	}
	ori = mudaDireccao(ori, dir);
	actualizaPosicao(&x, &y, ori, dir, dist);
  while (s != NULL){
    s = strtok(NULL, ",");
    if (s != NULL){
    	dir = s[1];
    	dist = 0;
    	i = 2;
	    while (s[i]!=0 && i<10){
	      dist = (dist * 10)+(s[i]-'0');
	      i++;
	    }
	    ori = mudaDireccao(ori, dir);
	    actualizaPosicao(&x, &y, ori, dir, dist);
    }
  }
  printf("A distancia é: %d\n",abs(x)+abs(y));
  return 0;
}

