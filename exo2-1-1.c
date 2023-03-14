#include <stdio.h>

double SeqAvgExt(double);

int main(){

    int status,count = 0;
    double rec,ans;

    while (1)
    {
    printf("データを入力してください:");
        status = scanf("%lf",&rec);

        if(status != 1){
            printf("\n");
            break;
        }
        count++;
         ans = SeqAvgExt(rec);
         printf("データの個数 = %d, ここまでの平均 = %f\n",count  ,ans);
    }

    printf("最終的な平均値は%fです。\n",ans);
    return 0;

}

double  SeqAvgExt(double c){
    static int cnt = 0;
    static double avg  =0.0;
    avg = avg * cnt;
    cnt += 1;
    avg = avg + c;
    avg = avg / cnt;

    return avg;
}
