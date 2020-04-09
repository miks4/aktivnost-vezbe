#include <stdio.h>
#include <stdlib.h>
typedef struct STABLO{
    int broj;
    struct STABLO *levi;
    struct STABLO *desni;

}stablo;
void dodaj(stablo **root, int broj){
    if(*root == NULL){

        stablo *novi = malloc(sizeof(stablo));
        novi->broj=broj;
        novi->desni = NULL;
        novi->levi = NULL;
        *root = novi;
        return;
    }
    if(broj < (*root)->broj){
        dodaj(&((*root)->levi),broj);
    }
    else {
        dodaj(&((*root)->desni),broj);
    }

}
void ispis(stablo *root,FILE *ulaz){
    if(root == NULL){
        return;
    }
    ispis(root->levi,ulaz);
    fprintf(ulaz,"%d",root->broj);
    ispis(root->desni,ulaz);
}
void saberiListove(stablo *root,FILE *izlaz){
    int suma = 0;
    for(int i = 0;root != NULL;i++){
        if(root->levi == NULL || root->desni == NULL){
            suma += root->broj;
        }

    }
    fprintf(izlaz,"%d",suma);

}
int main()
{
    stablo *root = NULL;
    FILE *ulaz = fopen("ulaz.txt","r");
    FILE *izlaz = fopen("izlaz.txt","w");
    if(ulaz == NULL){
        printf("nije se otvorio");
    }
    if(izlaz == NULL){
        printf("nije se otvorio");
    }

        dodaj(&root,4);
        dodaj(&root,5);
        dodaj(&root,6);
        dodaj(&root,7);
        dodaj(&root,8);
        dodaj(&root,2);
        dodaj(&root,3);
        dodaj(&root,1);
        dodaj(&root,9);
        dodaj(&root,10);
        dodaj(&root,11);
        dodaj(&root,12);
        dodaj(&root,15);
        dodaj(&root,14);
        dodaj(&root,19);
        dodaj(&root,20);

    ispis(root,ulaz);
    saberiListove(root,izlaz);

    fclose(ulaz);
    fclose(izlaz);
    return 0;
}
