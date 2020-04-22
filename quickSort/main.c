#include <stdio.h>
#include <stdlib.h>
void sort(int niz[],int pocetak,int kraj,int smer);
int quickSort(int poc,int krajj,int niz[],int smer);
int main()
{
    int niz[] = {4,6,2,7,3};
    int n = 5;
    sort(niz,0,4,1);
    int i;
    for(i = 0;i < n;i++){
        printf("%d\t",niz[i]);
    }
    return 0;
}
void sort(int niz[],int pocetak,int kraj,int smer){
    if(pocetak >= kraj){
        return;
    }
    int pivot = quickSort(pocetak,kraj,niz,smer);
    sort(niz,pocetak,pivot-1,smer);
    sort(niz,pivot+1,kraj,smer);
}
int quickSort(int poc,int krajj,int niz[],int smer){
    int p = niz[krajj];
    int a = poc-1;
    int i;
    for(i = poc; i < krajj;i++){
        if(smer == 0){
            if(niz[i] < p){
            a++;
            int temp = niz[i];
            niz[i] = niz[a];
            niz[a] = temp;
        }
        }
        else{
            if(niz[i] > p){
            a++;
            int temp = niz[i];
            niz[i] = niz[a];
            niz[a] = temp;
            }
        }


    }
    niz[krajj] = niz[a+1];
    niz[a+1] = p;
    return a+1;
}
