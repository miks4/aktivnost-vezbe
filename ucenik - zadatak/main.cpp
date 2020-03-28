#include <iostream>
#include <cstdlib>

using namespace std;
enum VRSTA_SKOLE{STRUCNA = 1,GIMNAZIJA,UMETNICKA};
enum STEPEN_OBRAZOVANJA{TRI_GOD = 1,CETIRI_GOD};
enum POZICIJA{KOD_KUCE,SKOLA,TRENING,BIBLIOTEKA};
class DJackaKnjizica{
private:
    int god;
    double prosek;
public:
    DJackaKnjizica(){
        god = 2;
        prosek = 4.7;
    }
    DJackaKnjizica(int gg,double pp){
        god = gg;
        prosek = pp;
    }
    DJackaKnjizica(const DJackaKnjizica &kopija){
        god = kopija.god;
        prosek = kopija.prosek;
    }
    void set_god(const int ggg){
        god = ggg;
    }
    void set_prosek(const double ppp){
        prosek = ppp;
    }
    int get_god()const{
        return god;
    }
    double get_prosek()const{
        return prosek;
    }
};

class Skola{
private:
    VRSTA_SKOLE skola;
    STEPEN_OBRAZOVANJA stepenObrazovanja;
public:
    Skola(){
        skola = GIMNAZIJA;
        stepenObrazovanja = CETIRI_GOD;
    }
    Skola(VRSTA_SKOLE sk,STEPEN_OBRAZOVANJA so){
        skola = sk;
        stepenObrazovanja = so;
    }
    Skola(const Skola &kopija){
        skola = kopija.skola;
        stepenObrazovanja = kopija.stepenObrazovanja;
    }

    void set_skola(const VRSTA_SKOLE skk){
        skola = skk;
    }
    void set_stepenO(const STEPEN_OBRAZOVANJA soo){
        stepenObrazovanja = soo;
    }
    VRSTA_SKOLE get_skola()const{
        return skola;
    }
    STEPEN_OBRAZOVANJA get_obrazovanje()const{
        return stepenObrazovanja;
    }

};

class Ucenik{
private:
    DJackaKnjizica knjizica;
    Skola sk;
    POZICIJA pozicija;
    int odmor;
    int vestina;
    int znanje;
public:
    Ucenik(){
        pozicija = KOD_KUCE;
        odmor = 90;
        vestina = 90;
        znanje = 90;
        }
    Ucenik(const Ucenik &kopija){
        pozicija = kopija.pozicija;
        odmor = kopija.odmor;
        vestina = kopija.vestina;
        znanje = kopija.znanje;
    }
    bool idi_kuci(){
        if(pozicija != KOD_KUCE){
        pozicija = KOD_KUCE;
        return true;
        }
        return false;
    }
    bool idi_na_trng(){
        if(pozicija == KOD_KUCE && odmor > 60){
            pozicija = TRENING;
            return true;
        }
        return false;
    }
    bool idi_u_biblioteku(){
        if(pozicija == KOD_KUCE || pozicija == SKOLA){
            pozicija = BIBLIOTEKA;
            return true;
        }
        return false;
    }
    bool idi_u_ucionica(){
        if(pozicija == BIBLIOTEKA){
            pozicija= SKOLA;
            return true;
        }
        return false;
    }
    bool spavaj(int satiSna){
        if(odmor < 100){
            odmor = satiSna*10;

        if(odmor > 100){
            odmor = 100;
            }
            return true;
        }
        return false;
    }
    bool uci(){
        if(pozicija == BIBLIOTEKA){
            znanje += rand()%10 + 1;
            if(znanje > 100){
                znanje = 100;
            }
            return true;
        }
        return false;
    }
    bool treniraj(){
        if(pozicija == TRENING){
            vestina += rand()%10 + 1;
            if(vestina > 100){
                vestina = 100;
            }
            return true;
        }
        return false;
    }

};
int main()
{

    return 0;
}
