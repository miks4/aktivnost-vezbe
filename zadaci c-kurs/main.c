#include <stdio.h>
#include <stdlib.h>

typedef struct STABLO{
    char naziv[20];
    int broj;
    struct STABLO *levi;
    struct STABLO *desni;
}stablo;
typedef struct LISTA{
        int br;
        struct LISTA *next;
}lista;
void dodaj(stablo **root, int broj, char *naziv);
void pronadji_najmanjiElement(stablo **root);
stablo* prondji_ntiEL(stablo *root,int n);
void ispisiOpseg(stablo *root,int a,int b);
void ispisiElBezPonavljanja(stablo *root,lista *head);
int nadji(stablo *root,int a);
int main()
{
    stablo *root = NULL;
    lista *head = NULL;
    dodaj(&root,3,"prvi");
    dodaj(&root,2,"drugi");
    dodaj(&root,5,"treci");
    dodaj(&root,7,"cetvrti");
    dodaj(&root,6,"peti");
    ///printf("n-ti najmanji :%d",prondji_ntiEL(root,3)->broj);
    ispisiOpseg(root,2,9);
    ispisiElBezPonavljanja(root,head);
    printf("manji ili jednak sa brojem,a najveci u stablu:%d",nadji(root,4));


    return 0;
}
void dodaj(stablo **root, int broj, char *naziv){
    if(*root == NULL){

        stablo *novi = malloc(sizeof(stablo));
        novi->broj=broj;
        strcpy(novi->naziv,naziv);
        novi->desni = NULL;
        novi->levi = NULL;
        *root = novi;
        return;
    }
    if(broj < (*root)->broj){
        dodaj(&((*root)->levi),broj,naziv);
    }
    else {
        dodaj(&((*root)->desni),broj,naziv);
    }

}
void pronadji_najmanjiElement(stablo **root){
    if(*root == NULL){
        return;
    }
    if((*root)->levi == NULL){
        free(*root);
        *root = NULL;
        return;
    }
     pronadji_najmanjiElement(&((*root)->levi));
}

stablo* prondji_ntiEL(stablo *root,int n){
    int i;
    for(i=0; i<n-1; i++){
        pronadji_najmanjiElement(&root);

    }
    while(root->levi != NULL){
        root = root->levi;
    }
    return root;
}

void ispisiOpseg(stablo *root,int a,int b){
    if(root == NULL){
        return 0;
    }
    ispisiOpseg(root->levi,a,b);
    if(a < root->broj && root->broj < b){
        printf("brojevi od a do b:%d\n",root->broj);
    }
    ispisiOpseg(root->desni,a,b);
}
void ispisiElBezPonavljanja(stablo *root,lista *head){
    if(root == NULL){
        return;
    }
    ispisiElBezPonavljanja(root->levi,head);
    lista *tek = head;
    int temp = 0;
    while(tek != NULL){
            if(root->broj == tek->br){
                temp = 1;
                break;
            }
         tek = tek->next;

    }
    lista *novi = malloc(sizeof(lista));
            novi -> next = head;
            head = novi;
            novi->br = root->broj;
    if(temp == 0){

        printf("%d\n",root->broj);
    }
    ispisiElBezPonavljanja(root->desni,head);
}
int nadji(stablo *root,int a){
    if(root == NULL){
        return -1;
    }
    if(root->broj == a){
        return root->broj;
    }
    else if(root->broj < a){
        int x = nadji(root->desni,a);
        if(x == -1){
            return root->broj;
        }
        else{
            return x;
        }
    }
    else{
        int y = nadji(root->levi,a);
    }

}
