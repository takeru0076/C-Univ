#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int main(){
    char first_filename[] = "output03.txt";
    char second_filename[] = "output03-example.txt";
    FILE *fpin,*fpout;

    char buf1[MAX],buf2[MAX];
    int c,d,n,m,i,cnt = 0;

    if((fpin = fopen(first_filename, "r")) == NULL){
                printf("Failed to open: %s\n", first_filename);
                exit(1);
        }

        if((fpout = fopen(second_filename, "r")) == NULL){
                printf("Failed to open: %s\n", second_filename);
                exit(2);
        }

    for(n = 0; n < MAX; n++){
                if((c = fgetc(fpin)) == EOF){
                        break;
        }
                buf1[n] = (char)c;
    }
    if(n == MAX){
                printf("Buffer overflow !\n");
                exit(3);
        }

    for(m = 0; m < MAX; m++){
                if((d = fgetc(fpout)) == EOF){
                        break;
        }
                buf2[m] = (char)d;
    }
    if(m == MAX){
                printf("Buffer overflow !\n");
                exit(4);
        }

    if(n != m){
      printf("Not equal n(%d) and m(%d).\n",n,m);
    }

    if(n == m){
         for(i = m; i >= 0; i--){
                    if(buf1[i] != buf2[i]){
                cnt++;
                printf("Two files are different at %d byte.\n",cnt);
            }
             }
         if(cnt == 0){
             printf("Two files are identical.\n");
         }
    }
        fclose(fpout);
        fclose(fpin);

    return 0;
}

