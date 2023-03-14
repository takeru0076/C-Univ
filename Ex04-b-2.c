#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 4
 
int main(){
 
	char code_file[] = "country-code.txt";
	FILE *fp;
	
	char typein[N];
	char pickup[N];
	
	int count,l,i;
	
	while(1){
		count = 0;
		i = 0;

		printf("Input a code: ");
		if(scanf("%s", typein) == EOF)
			break;
			
		if((fp = fopen(code_file, "r")) == NULL){
			printf("Failed to open: %s\n", code_file);
			exit(2);
		}
		
		/* 
		 * ここに，国名コードファイルのコードを1つずつ読み込みながら，
		 * 入力されたコードと一致するかをチェックする処理を追加せよ
		 */

			while(fscanf(fp,"%s",pickup) != EOF){
			    l = strcmp(typein,pickup);
				if(l == 0){
				   printf("The code \"%s\" is found.\n\n",typein);
				   count++;
				   break;
				}

			}
			if (count == 0)
				{
					printf("The code \"%s\" is not found.\n\n",typein);
				}
		fclose(fp);
	}
	
	printf("\n");
	return 0;
}