#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct elLista{
        char ime[20];
        char prezime[20];
        int brPoena;
        struct elLista *next;
}lista;
void ucitaj(lista **head,FILE *ulaz){
    char ime[20];
    char prezime[20];
    int brPoena;
    lista *tek = NULL;
    for(int i = 0;fscanf(ulaz,"%s %s %d",ime,prezime,&brPoena)!= EOF;i++){
            lista *novi = malloc(sizeof(lista));

        strcpy(novi->ime,ime);
        strcpy(novi->prezime,prezime);
        novi->brPoena = brPoena;
        novi->next = NULL;
        if(i == 0){
            *head = novi;
        }
        else{
            tek->next = novi;
        }
        tek = novi;

    }
}
void ispisPreZamene(lista *head,FILE *izlaz){
    while(head != NULL){
        fprintf(izlaz,"%d\t",head->brPoena);
        head = head->next;
    }
}
void ispisPosleZamene(lista **head,FILE *izlaz){
    int max = -1;
    int min = 101;
    int indeksMin;
    int indeksMax;
    lista *pretMin;
    lista *pretMax;
    lista *tren = (*head);
    lista *tretPret = NULL;
    lista *minEl;
    lista *maxEl;
    for(int i=0;tren != NULL;i++){
        if(tren->brPoena < min){
            min = tren->brPoena;
            indeksMin = i;
            pretMin = tretPret;
            minEl = tren;
        }
        if(tren->brPoena > max){
            max = tren->brPoena;
            indeksMax = i;
            pretMax = tretPret;
            maxEl = tren;
        }
        tretPret = tren;
        tren = tren->next;
    }
    lista *temp;
    if(pretMax == NULL){
            lista *temp2 = minEl;
            temp = (*head);
        (*head) = minEl;
    (*head)->next = temp->next;
    pretMin->next = maxEl;
    maxEl->next = temp2->next;
    return;
    }
    if(pretMin == NULL){
        lista *temp2 = maxEl;
        temp = (*head);
        *head = maxEl;
        (*head)->next = minEl->next;
        pretMax->next = minEl;
        minEl->next = temp2->next;
        return;
    }
    lista *temp1 = maxEl;
    lista *temp2 = minEl;
    pretMin->next = maxEl;
    pretMax->next = minEl;
    maxEl->next = temp2->next;
    minEl->next = temp1->next;


}
void izracunajSrednjuVrednost(lista *head,FILE *izlaz){
    if(head == NULL){
        return;
    }
    int suma = 0;
    int avg;
    int br = 0;
    while(head != NULL){
        suma += head->brPoena;
        head=head->next;
        br++;

    }
    avg = suma / br;
    fprintf(izlaz,"%d",avg);
}
int main()
{
    lista *head = NULL;
    FILE *ulaz = fopen("ulaz.txt","r");
    FILE *izlaz = fopen("izlaz.txt","w");
    if(ulaz == NULL){
        printf("nije otvoren");
    }
    if(izlaz == NULL){
        printf("nije otvoren");
    }
    ucitaj(&head,ulaz);
    ispisPreZamene(head,izlaz);
    ispisPosleZamene(&head,izlaz);
    ispisPreZamene(head,izlaz);
    izracunajSrednjuVrednost(head,izlaz);
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}
