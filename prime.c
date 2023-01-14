#include<stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[]){
    int max = atoi(argv[1]);
    int isprime = 1;
    int pcount = 0;
    int maxdiv = 0;
    double ratio = 0;
    int lastdiv = 0;

    //printf("%d\n",max);
    //printf("%d\n",argc);

    for (int i = 3 ; i < max ; i++){
        isprime = 1;
        for (int j = 2 ; j < i ; j++){
           if (i % j == 0 ){
            isprime = 0;
            lastdiv = j;
            if (j > maxdiv){
                maxdiv = j;
            
            }
            break;
           }
           
        }
        if (isprime == 1){
            printf("%d\n",i);
            pcount++;
           
        } 

    } 
    ratio = (double)maxdiv/(double)max;
    printf("\n");
    printf("Count %d\n",pcount);
    printf("Max div %d\n",maxdiv);
    printf("Max div percent %f\n", ratio);
    printf("Last div %d\n", lastdiv);

}

