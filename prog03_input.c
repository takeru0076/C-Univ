#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prog03.h"

int input_planet(Planet *planet){
    FILE *fp;
    int result,i=0;

    if((fp = fopen("planet.txt","r")) == NULL){
        return -1;
    }

    while(1){
        result = fscanf(fp,"%s%lf%lf%lf",planet[i].name,&planet[i].radius,&planet[i].density,&planet[i].orbital_radius);
        i++;
        if(result != 4){
            break;
        }
    }
    return 0;
}