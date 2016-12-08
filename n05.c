#include <openssl/md5.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

int main(){
  //char input[]="wtnhxymk";
  char input[]="abc";
  char testMD5[1024];
  char *md5;
  int i=0;
  int j=0;
  while (j<8){
    sprintf(testMD5, "%s%d", input, i);
    md5 = str2md5(testMD5, strlen(testMD5));//calcMD5(testMD5);
    if(md5[0] == '0' && md5[1] == '0' && md5[2] == '0' && md5[3] == '0' && md5[4] == '0'){
      printf("%c - %d\n", md5[5], i);
      j++;
    }
    i++;
  }
  return 0;
}
