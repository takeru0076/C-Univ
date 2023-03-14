#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main() {
    char c,word[MAX];
    
    int i,count = 0,FILE *fpin, *fpout;check;

    if((fpin = fopen("input01.txt", "r")) == NULL){
      printf("failed, inout\n");
      exit(1);
     }

     if((fpout = fopen("output01.txt", "w")) == NULL){
       printf("failed, output\n");
        exit(2);
    }

      while((c = fgetc(fpin)) != EOF){
        word[count] = c;
        count++;
        check = count;
      }

      for(i = 0; i < check; i++){
        if((word[i] >= 'A') && (word[i] <= 'Z')){
          word[i] = word[i] + ('a' - 'A');
        }

        fprintf(fpout,"%c",word[i]);
      }
      fprintf(fpout,"\n");
      fprintf(fpout,"\n");

      for(i = 0; i < check; i++){
        if((word[i] >= 'a') && (word[i] <= 'z')){
          word[i] = word[i] - ('a' - 'A');
        }

        fprintf(fpout,"%c",word[i]);
      }
      fprintf(fpout,"\n");
      fprintf(fpout,"\n");

      for(i = 0; i < check; i++){
        if((word[i] >= 'A') && (word[i] <= 'Z')){
          word[i] = word[i] + 0x20;
          fprintf(fpout,"%c",word[i]);
        } else if((word[i] >= 'a') && (word[i] <= 'z')){
          word[i] = word[i] - 0x20;
          fprintf(fpout,"%c",word[i]);
        }
      }
      fprintf(fpout,"\n");
      fprintf(fpout,"\n");
    return 0;

}