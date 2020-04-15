#include <stdio.h>
#include <stdlib.h>
int pronadji(int niz[],int a);
int nadjiElemente(int niz[],int a);
int nadjiElementeRekurzivno(int niz[],int a,int pocetak,int kraj);
int main()
{
    int niz[] = {11, 5 ,7 ,9 ,1 ,55 ,12};
    int n = 7;
    for(int i = 0; i < n-1;i++){
            int min = niz[i];
            int indeksMin = i;
        for(int j = i+1;j < n;j++){
            if(niz[j] < min){
                min = niz[j];
                indeksMin = j;
            }
        }
        if(min < niz[i]){
        niz[indeksMin] = niz[i];
        niz[i] = min;
      }
    }
    for(int i = 0;i < n;i++){
        printf("selection sort:%d\t",niz[i]);
    }
    printf("insertion sort===>>>");
    int nizz[] = {9,3,6,2,5};
    int y = 5;
    int j;
    for(int i = 1; i < y;i++){
        int a = nizz[i];

        for(j = i-1;j >= 0;j--){
            if(a < niz[j]){
                nizz[j+1] = nizz[j];
            }
            else{

                break;
            }
        }
        nizz[j+1] = a;
    }
    printf("BINARNA PRETRAGA===>>>");
    int sortiranNiz[] = {1,2,3,4,5,6,7,8,9};

    printf("%d",pronadji(sortiranNiz,4));
    printf("%d",nadjiElemente(sortiranNiz,4));
    printf("%d",nadjiElementeRekurzivno(sortiranNiz,4,0,9));

    return 0;
}
int pronadji(int niz[],int a){
    int pocetak = 0;
    int kraj = 9;
    while(pocetak <= kraj){
        int sredina = (pocetak + kraj) / 2;
        if(a == niz[sredina]){
            return sredina;
        }
        else if(a < niz[sredina]){
            kraj = sredina - 1;
        }
        else{
            pocetak = sredina + 1;
        }
    }
    return -1;
}
int nadjiElemente(int niz[],int a){
    int pocetak = 0;
    int kraj = 9;
    while(pocetak <= kraj){
        int sredina = (pocetak + kraj) / 2;
        if(a == niz[sredina]){
                int br = 1;
                int i = sredina-1;
                while(i >= pocetak){
                    if(niz[i] == a){
                        br++;
                    }
                    else{
                        break;
                    }
                    i--;
                }
                i = sredina+1;
                while(i <= kraj){
                    if(niz[i] == a){
                        br++;
                    }
                    else{
                        break;
                    }
                    i++;
                }
            return br;
        }
        else if(a < niz[sredina]){
            kraj = sredina - 1;
        }
        else{
            pocetak = sredina + 1;
        }
    }
    return -1;
}
int nadjiElementeRekurzivno(int niz[],int a,int pocetak,int kraj){

    if(pocetak > kraj){
        return -1;
    }
    int sredina = (pocetak + kraj) / 2;
    if(niz[sredina] == a){
        return sredina;
    }
    if(niz[sredina] > a){
        return nadjiElementeRekurzivno(niz,a,pocetak,sredina-1);
    }
    else{
        return nadjiElementeRekurzivno(niz,a,sredina+1,kraj);
    }

}
