#include <stdio.h>
#include <stdlib.h>

typedef struct ARTIKAL{
    int sifra;
    double cena;
    char naziv[];
}artikal;

typedef struct PRODAVNICA{
    char naziv[20];
    artikal *artikli;
    int brArtikala;
}prodavnica;

void postaviNaziv(){
    printf("unesite naziv prodavnice");
    scanf("%s",&prodavnica.naziv[20]);

}
int meni(){
    int i;
    printf("izaberite operaciju");
    printf("1.postavi naziv prodavnice\n");
    printf("2.dodaj artikal\n");
    printf("3.obrisi artikal za sifru\n");
    printf("4.obrisi sve artikle\n");
    printf("5.pronadji artikal preko sifre\n");
    printf("6.prikazi artikle\n");
    printf("7.kraj\n");
    scanf("%d",&i);
    return i;
}
int main()
{
    prodavnica *p;
    do{
        switch(meni()){
    case 1:
        postaviNaziv();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        return 0;
    default:
        printf("ne postoji operacija,izaberite novu");
        break;

        }
    }while(1);
    return 0;
}
