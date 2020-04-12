#include <stdio.h>
#include <stdlib.h>

typedef struct ARTIKAL{
    int sifra;
    double cena;
    char naziv[20];
}Artikal;

typedef struct PRODAVNICA{
    char nazivProdavnice[20];
    Artikal *artikli;
    int brArtikala;
}Prodavnica;

Prodavnica *p;

void postaviNaziv(){
    printf("unesite naziv prodavnice:");
    int i;
    char NoviNaziv[20];
    scanf("%s",NoviNaziv);
    for(i = 0;NoviNaziv[i]!='\0';i++){
        p->nazivProdavnice[i] = NoviNaziv[i];
    }
    p->nazivProdavnice[i] = '\0';
    printf("==============================\n");
}
void dodajArtikal(){
    if(p->brArtikala > 0){
        Artikal *noviArtikal = malloc(sizeof(Artikal)*(p->brArtikala));
        int i,a;
        for(i = 0;i<p->brArtikala;i++){
            noviArtikal[i].cena = p->artikli[i].cena;
            noviArtikal[i].sifra = p->artikli[i].sifra;
            for(a = 0;p->artikli[i].naziv[a] != '\0';a++){
                noviArtikal[i].naziv[a] = p->artikli[i].naziv[a];
            }
            noviArtikal[i].naziv[a] = '\0';

        }
        free(p->artikli);
        p->artikli = malloc(sizeof(Artikal)*(p->brArtikala+1));
        for(int i = 0;i < p->brArtikala;i++){
            p->artikli[i].cena = noviArtikal[i].cena;
            p->artikli[i].sifra = noviArtikal[i].sifra;
            for(a = 0;noviArtikal[i].naziv[a] != '\0';a++){
                p->artikli[i].naziv[a] = noviArtikal[i].naziv[a];
            }
            p->artikli[i].naziv[a] = '\0';
        }
        free(noviArtikal);

    }
    else{
        p->artikli = malloc(sizeof(Artikal));
    }
    printf("%d. artikal\n",p->brArtikala+1);
    printf("=======================\n");
    printf("=======================\n");
    printf("unesite naziv artikla: ");
    scanf("%s",p->artikli[p->brArtikala].naziv);
    printf("unesite sifru: ");
    scanf("%d",&p->artikli[p->brArtikala].sifra);
    printf("unesite cenu: ");
    scanf("%lf",&p->artikli[p->brArtikala].cena);
    p->brArtikala++;
}
void obrisiSifru(int pass){
    int q = 0;
    if(p->brArtikala > 0){
        for(int i = 0;i < p->brArtikala;i++){
            if(pass == p->artikli[i].sifra){
                q = 1;
                break;
            }
        }
        if(q == 0){
            printf("ne postoji sifra koju ste uneli\n");
            return;
        }
        Artikal *noviArtikal = malloc(sizeof(Artikal)*(p->brArtikala));
        for(int i = 0,a;i < p->brArtikala;i++){
            noviArtikal[i].cena = p->artikli[i].cena;
            noviArtikal[i].sifra = p->artikli[i].sifra;
            for(a = 0;p->artikli[i].naziv[a] != '\0';a++){
                noviArtikal[i].naziv[a] = p->artikli[i].naziv[a];
            }
            noviArtikal[i].naziv[a] = '\0';
        }
        free(p->artikli);
        p->artikli = malloc(sizeof(Artikal)*(p->brArtikala-1));
        for(int i = 0,b = 0,a;i < p->brArtikala;i++){
                if(pass != noviArtikal[i].sifra){
            p->artikli[b].cena = noviArtikal[i].cena;
            p->artikli[b].sifra = noviArtikal[i].sifra;
            for(a = 0;noviArtikal[i].naziv[a] != '\0';a++){
                p->artikli[b].naziv[a] = noviArtikal[i].naziv[a];
            }
            p->artikli[b].naziv[a] = '\0';
            b++;
            }
        }
        p->brArtikala--;
        printf("uspesno obrisan artikal");
        free(noviArtikal);

    }
    else{
        printf("\nnemate ni jedan artikal\n\n\n");
    }
}
void obrisi(){
    if(p->brArtikala > 0){
    free(p->artikli);
    p->brArtikala = 0;
    printf("obrisali ste sve artikle");
    }
    else{
        printf("nemate ni jedan artikal,nemate sta da obrisite");
    }
}
Artikal *pronadjiArtikal(int pass){
    for(int i = 0;i < p->brArtikala;i++){
        if(pass == p->artikli[i].sifra){
            return &p->artikli[i];
        }
    }
    return NULL;
}
void ispis(){
    printf("naziv prodavnice:%s\n\n",(p->nazivProdavnice == '\0')?"niste dali prodavnici ime":p->nazivProdavnice);
    for(int i = 0;i < p->brArtikala;i++){
        printf("\nnaziv:%s \ncena:%.2lf \nsifra:%d \n",p->artikli[i].naziv,p->artikli[i].cena,p->artikli[i].sifra);
    }
}
int meni(){
    int i;
    printf("\n======================================\n");
    printf("\nizaberite operaciju\n");
    printf("1.postavi naziv prodavnice\n");
    printf("2.dodaj artikal\n");
    printf("3.obrisi artikal pomocu unosa sifre\n");
    printf("4.obrisi sve artikle\n");
    printf("5.pronadji artikal preko sifre\n");
    printf("6.prikazi artikle\n");
    printf("7.kraj\n");
    printf("\n======================================\n");
    scanf("%d",&i);
    return i;
}
int main()
{
    p = malloc(sizeof(Prodavnica));
    p->nazivProdavnice[0] = '\0';
    p->brArtikala = 0;
    int pass;
    do{
        switch(meni()){
    case 1:
        postaviNaziv();
        break;
    case 2:
        dodajArtikal();
        break;
    case 3:
        printf("unesite sifru artikla za brisanje: ");
        scanf("%d",&pass);
        obrisiSifru(pass);
        break;
    case 4:
        obrisi();
        break;
    case 5:
        printf("unesite sifru kako bismo po njoj pronasli artikal: ");
        scanf("%d",&pass);
        Artikal *temp = pronadjiArtikal(pass);
        if(temp == NULL){
            printf("nismo nista pronasli\n");
        }
        else{
            printf("naziv:%s \ncena:%.2lf \nsifra:%d \n\n",temp->naziv,temp->cena,temp->sifra);
        }
        break;
    case 6:
        ispis();
        break;
    case 7:
        return 0;
    default:
        printf("ne postoji operacija,izaberite novu");
        break;

        }
    }while(1);
    obrisi();
    free(p);
    return 0;
}
