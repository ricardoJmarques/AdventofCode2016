#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char input[] = {"LUULRUULULLUDUDULDLUDDDLRURUDLRRDRDULRDDULLLRULLLURDDLRDLUUDDRURDDRDDDDRDULULLLLURDDLLRLUUDDDRLRRRDURLDDLRRLDUDRRRDLDLRRDLDLUURRLRULLULRUDRDLRUURLDRDLRLDULLLUDRDDRLURLUUDRLLLDRUUULLUULRUDDUDRDUURRRUDRLDDUURDUURUDRDDLULDDUDUDRRDDULUDULRDRULRLRLURURDULRUULLRDDDDRRUUDDDUUDRLLRUDRLRDLRRLULRLULRUDDULRLLLURLDDRLDDLRRLDRDDDRRLRUDRULUUDUURLDLRRULUDRDULDLLRRURRDDLRRRLULUDUUDDUDDLRDLRDRLRLDUDUDDUDLURRUURDRLRURLURRRLRLRRUDDUDDLUDRLUURUUDUUDDULRRLUUUDRLRLLUR\nLDLLRRLDULDDRDDLULRRRDDUDUDRRLLRUUULRUDLLRRDDRRLDDURUUDLUDRRLDURDDRUDLUDUUDLDLLLDLLLDRLLDLRUULULLUUDULDUUULDDLRUDLLUDLUUULDRLUDRULUUDLDURDLDUULLRDUDRDLURULDLUUUDURLDDRLLDRLRDDDUDRUULLDLUDRRDDLDLUURUDDLDRURRLULUDDURLDRDRDUDDRRULRLDURULULRURDUURRUDRDDRDRLDRDUUDLRULRDDDULRURUDRUUULUUDDLRRDDDUDRLRUDRDLRRUDLUDRULDDUDLRLDDLDRLRDLULRDRULRLLRLUDUURULLLDDUULUUDDDUDRRULDDDULRUDRRLRLLLUDLULDUUULDDULDUUDLUULRDLDUDRUDLLDLDLLULDDDDLUDDUDRUDLRRRDDDDDLLRRDRUUDDDRRULRUDUUDRULLDLLLDDRDDUURLUUURUDRUDURLRUUUULUUURDRRRULDUULDLDDDRDDDDLLDRUDRDURLDDURDURULDDRLLRRLDUDRDURRLDRDLLULUUUD\nLDDLRLRDDRLRUDDRDDUDRULUUULULDULRUULLRRDUULRDUUDDDRRULDDUDRLLLDULURDLDDRLLRURULULDLDULRDLDLRULUDLLDRUDLDURRDULDDRLRURDLLUDRDDDUDLUDULURULRDRLRULDLLRLDRRUDRDRUDRLDLRLUUURURRRLDDULLULLLRLRLULDLLRLDDRLDULURULRUURRUUURRUDRLRRURURDDDRULDULDLDLRRRLLDDRRURRULULULDRDULDRRULDUDRRLDULDRDURRDULLRRRLLLLRRLLRRRDRURDUULLURURURDDRRDRLLLULRRRDRLDRLDRDLLRUUDURRDRRDLLUDLDRLRLDLUDRDULRULRRLLRDLULDRLUDUUULLDRULDDLLRDUUUDRUUUUULUURDDLLDUURURRURLLURRDDUDUDRUUDDRDDRRLRLULRLRRRDRLLRRLLLDUULLUUDDLULLLDURRLLDRLDRDRLRRLRRULRRRRLRRRRRURUDULUULRDLLDRLRRDUURDRRUDRURRRDDRLDDLRLUDRDRDRRLDDDRDDRRRDUDULRURRDRDLLDRUD\nUUUDLDDLRDLLLLRUUURDDLLURRUUURLUULLURUUDUDLDULULLRRRRLLLRDLLUDRUURDRURUDRURRLRLDRURLUDRLULRRURDDDURLLDULDLRRRDUUDDDRDLRUURRDRDRLRDLULRLDDRULRULDRDUDRUURLDLUDDULLLRURRLURLULDRRLUUURURLDLDDULLLRUUURDDDUURULULLUUUDUDRLLRRULUULDDDLLUDLURLLLRRULLURDRLUUDDLLDLLLUDULLRDRRRURDRUDUDUULUDURDLRUDLLRDDRURUDURLRULURDDURULLRDDRLRRDRLLULRDDDULRDLRULDDLRRDULDLUURRURUULRRDUURUDRRRRRLDULDLRURRULULDLRDDDRLLDURRULDUDUDRRRLUULRLUDURRRLRLDURRRRUULDRLUDDDUDURLURUDLLUDRDDDRLLURLRLDDURUUDDDUDUR\nRURRRRURUDDRLURUDULRDUDDDUURULDRRRRURDLDRRLLDLUDLRRLRRUULLURULLRDLLRDDDDULLRLLDDLLRUDDULDUDLDURLRUULDDURURDURDLDRRULRURRRRRLRRLLUDURRURULRLRDLRLRRRLLURURDLLLDLDDULDLUDDLLLRUDDRDRLRUDRRLDDLRDLRLRLRLRRDUUURRUDRRLDLRRUULULLUDRRRUDLURDRUULDRDRRLUULULDDLURRLDULLURLDRLDULDRLLDLUUULLULRRDDRURRURLDLDRRLLLLLUDUURUULURLRDDDLRRRRLLLURUDLDDRDDRRUDURUULDRRULLLRRLRULLLRLDDLLRRLRURLRDRUDULLDDLDDDDDLDURURDLULRDDLRDLLRURLLRDLRUDDRDRRDURDURLUDRLDUDDDRRURRLUULURULLRLRDLRRLRURULLDDURLLRRRUDDRDLULURRRUUUULUULRRLLDLRUUURLLURLUURRLRL\0"};
	int x=1;
  int y=1;
  int i=0;
  int matriz[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  /*
   y\x 0  1  2
    0 [1][2][3]
    1 [4][5][6]
    2 [7][8][9]
  LUUL RUUL ULLU DUDU LDLU DDDL
  7
  */
  
  while (input[i]!=0){
    switch(input[i]){
    	case 'U':
    	  if (y>0) y--;
      break;
      case 'D':
       if (y<2) y++;
      break;
      case 'L':
        if (x>0) x--;
      break;
      case 'R':
        if (x<2) x++;
      break;
      default:
      	printf("%d", matriz[y][x]);
      break;
    }
    i++;
  }
  printf("%d\n", matriz[y][x]);
  return 0;
}
