#include <stdio.h>
#include <stdlib.h>

char scoretograde(int);

int main(int argc, char *argv[]){

    if(argc == 1){
        return 0;
    }

    int i,score[argc];
    char grade[argc];

    for(i = 1; i < argc; i++){
        score[i] = atoi( argv[i]);
    }

    for(i = 1; i < argc; i++){
        grade[i] = scoretograde(score[i]);
    }

    for(i = 1; i < argc; i++){
        printf("Score:%d Grade:%c\n",score[i], grade[i]);
    }


    return 0;
}

char scoretograde(int x){
    if(80 <= x && x <= 100){
        return 'A';
    } else if(65 <= x && x <= 79){
        return 'B';
    }else if(50 <= x && x <= 64){
        return 'C';
    }else if(35 <= x && x <= 49){
        return 'D';
    } else {
        return 'F';
    }
}