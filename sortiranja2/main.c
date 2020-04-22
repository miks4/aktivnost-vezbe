#include <stdio.h>
#include <stdlib.h>
void margeSort(int niz[]);
void podNiz(int poc,int krajj,int niz[]);
void spoji(int poc,int krajj,int niz[]);
int main()
{
    int niz[] = {5,7,2,4,9};
    int n = 5;
    margeSort(niz);
    int i;
    for(i = 0;i < n;i++){
        printf("%d\t",niz[i]);
    }

    return 0;
}
void margeSort(int niz[]){
    int pocetak = 0;
    int kraj = 4;
    podNiz(pocetak,kraj,niz);
}
void podNiz(int poc,int krajj,int niz[]){
    if(poc >= krajj){
        return;
    }
    int sredina = (poc + krajj) / 2;

    podNiz(poc,sredina,niz);
    podNiz(sredina+1,krajj,niz);

    spoji(poc,krajj,niz);
}
void spoji(int poc,int krajj,int niz[]){
    int sredina = (poc + krajj) / 2;
    int levi[sredina - poc + 1];
    int desni[krajj - sredina];
    int i;
    for(i = poc;i <= sredina;i++){
        levi[i - poc] = niz[i];
    }

    for(i = sredina+1;i <= krajj;i++){
        desni[i - sredina - 1] = niz[i];
    }
    i = 0;
    int j = 0,k = poc;
    while(i < (sredina-poc+1) && j < (krajj - sredina)){
        if(levi[i] > desni[j]){   ///opadajuci    za rastuci ide manje <;
            niz[k] = levi[i];
            i++;
        }
        else{
            niz[k] = desni[j];
            j++;
        }
        k++;
    }
    while(i < (sredina - poc + 1)){
        niz[k] = levi[i];
        i++;
        k++;
    }
    while(j < (krajj - sredina)){
        niz[k] = desni[j];
        j++;
        k++;
    }
}
