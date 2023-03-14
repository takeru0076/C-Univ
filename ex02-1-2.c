include <stdio.h>

void SeqAvgExt(double);

int cnt = 0;
double avg = 0.0;

int main(){

    int status;
    double rec;

    while (1)
    {
    printf("データを入力してください:");
        status = scanf("%lf",&rec);

        if(status != 1){
            printf("\n");
            break;
        }
         SeqAvgExt(rec);
         printf("データの個数 = %d, ここまでの平均 = %f\n",cnt , avg);
    }

    printf("最終的な平均値は%fです。\n",avg);
    return 0;

}

void SeqAvgExt(double c){
    avg = avg * cnt;
    cnt += 1;
    avg = avg + c;
    avg = avg / cnt;
}
