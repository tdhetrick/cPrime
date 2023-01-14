#include<stdio.h>
#include <stdlib.h>
#include <math.h>

    
#define maxdivs 10000

struct div
{
    int num;
    int count;
};

struct div divs[maxdivs];
int lastdiv = 0;

/*
    void divsSort(struct div arr[], int last){
        int i, j;
        for (i = 0; i < last - 1; i++){
   
            // Last i elements are already in place
            for (j = 0; j < last - i - 1; j++){
                if (arr[j].num > arr[j + 1].num){
                    swap(&arr[j].num, &arr[j + 1].num);
                }                   
            }               
        }
    }

    int divsSearch(struct div arr[], int l, int r, int x) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
            if (arr[mid].num == x) 
                return mid; 
            if (arr[mid].num > x) 
                return binarySearch(arr, l, mid - 1, x); 
            return binarySearch(arr, mid + 1, r, x); 
        } 
        return -1; 
    }
*/
    int divsFind( int x){

        for(int i = 0; i < maxdivs; i++){
            if (divs[i].num == x){
                return i;
            }
        }

        return -1;
    }

    void adddiv(int num){

        int ixat = divsFind(num);
        //printf("%d \n",ixat);
        if (ixat >= 0){
            divs[ixat].count  = divs[ixat].count + 1;
        }else {
             divs[lastdiv + 1].num  = num;
             divs[lastdiv + 1].count  = 1;
            lastdiv++;

        }

    }

    void printDivs(){
        for (int i = 0 ; i < lastdiv;i++){
            printf("%d, ct: %d \n",divs[i].num,divs[i].count );
        }
    }


void main(int argc, char *argv[]){
    const int max = atoi(argv[1]);
    int isprime = 1;
    int pcount = 0;
    int maxdiv = 0;
    double ratio = 0;
    int lastdiv = 0;


    for (int i = 3 ; i < max ; i = i +2){
        isprime = 1;
        for (int j = 2 ; j < sqrt(i) ; j++){
           if (i % j == 0 ){
                isprime = 0;
                lastdiv = j;
                adddiv(j);
                if (j > maxdiv){
                    maxdiv = j;
                }
                break;
            }
           
        }
        if (isprime == 1){
            //printf("%d\n",i);
            pcount++;
           
        } 

    } 
    
    ratio = (double)maxdiv/(double)max;
    printf("\n");
    printDivs();
    printf("Count %d\n",pcount);
    printf("Max div %d\n",maxdiv);
    printf("Max div percent %f\n", ratio);
    printf("Last div %d\n", lastdiv);

}

