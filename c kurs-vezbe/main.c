#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Pizza{
    int cena;
    char drzava[4];
    char grad[3];
    char naziv[21];
    struct Pizza *next;

}pizza;
void ucitajUListu(pizza **head,FILE *ulaz);
void dodajUListu(pizza **head,int cena,char *drzava,char *grad,char *naziv);
void ispisiListu(pizza *head,FILE *izlaz);
void pronadjiProsek(pizza *head,char *drzava,FILE *izlaz);
int main()
{
    pizza *head = NULL;
    FILE *ulaz = fopen("ulaz.txt","r");
    FILE *izlaz = fopen("izlaz.txt","w");
    if(ulaz == NULL){
        printf("nije otvoren");
        return 1;
    }
    if(izlaz == NULL){
        printf("nije otvoren");
        return 2;
    }
    ucitajUListu(&head,ulaz);
    ispisiListu(head,izlaz);
    pronadjiProsek(head,"srb",izlaz);
    fclose(ulaz);
    fclose(izlaz);
        return 0;
}
void ucitajUListu(pizza **head,FILE *ulaz){
    int cena;
    char drzava[4];
    char grad[3];
    char naziv[21];

    while(fscanf(ulaz,"%d %s %s %s",&cena,drzava,grad,naziv)!= EOF){
        dodajUListu(head,cena,drzava,grad,naziv);

    }

}
void dodajUListu(pizza **head,int cena,char *drzava,char *grad,char *naziv){
    if(*head == NULL){
        pizza *novi = malloc(sizeof(pizza));
        novi->cena = cena;
        strcpy(novi->drzava,drzava);
        strcpy(novi->grad,grad);
        strcpy(novi->naziv,naziv);
        novi->next = NULL;
        *head = novi;
        return;
    }
    dodajUListu(&((*head)->next),cena,drzava,grad,naziv);

}
void ispisiListu(pizza *head,FILE *izlaz){
    if(head == NULL){
        return;
    }
    fprintf(izlaz,"%d %s %s %s\n",head->cena,head->drzava,head->grad,head->naziv);
    ispisiListu(head->next,izlaz);
}
void pronadjiProsek(pizza *head,char *drzava,FILE *izlaz){
    int suma = 0;
    int brojac = 0;
    while(head != NULL){
        if(strcmp(head->drzava,drzava)== 0){
            suma += head->cena;
            brojac++;
        }
        head = head->next;
    }
    float avg;
    avg = (float)suma / brojac;
    fprintf(izlaz,"avg=%.2f",avg);
}
