#include <stdio.h>
#define N 256 /* ??? にはバッファ配列に最大文字数の文字列を適切に格納可能な数値を指定する */

char change (char);
 
int main(){
	char str[N], str_new[N],s;
    int i, count = 1;
	
	/* 適宜変数を追加すること */
	
	printf("Input : ");
	scanf("%s", str); /* 文字列を標準入力から入力 */

    str_new[0] = '[';

    for(i = 1;; i++){
        str_new[i] = str[i - 1];

        if(str_new[i] == '\0'){
            break;
        }

        s = change(str_new[i]);

        str_new[i] = s;

        count++;

    }

    str_new[count] = ']';
    str_new[count +1] = '\0';

	
	/*
	 * 最初の開括弧を代入し
	 * 入力した文字列を1文字ずつチェックし，
	 * 英数字（すなわち0-9, A-Z, a-z）ならそのまま str_new にコピー，
	 * それ以外なら str_new に'_'を代入する，
	 * さらに，最後の閉括弧を代入し，
	 * str_new の末尾の処理（ヌル文字）が必要となる
	 */
	
	printf("Before : %s\n", str);
	printf("After  : %s\n", str_new);
	
	return 0;
}


char change (char t){
    if((t >= 'A') && (t <= 'Z') || (t >= 'a') && (t <= 'z') || (t >= '0') && (t <= '9'))
    {
          return t;
    } else {
        return '_';
    }
}