#include <iostream>
#include <cstdlib>

using namespace std;
enum VRSTA_SKOLE{STRUCNA = 1,GIMNAZIJA,UMETNICKA};
enum STEPEN_OBRAZOVANJA{TRI_GOD = 1,CETIRI_GOD};
enum POZICIJA{KOD_KUCE = 1,SKOLA,TRENING,BIBLIOTEKA};
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
    STEPEN_OBRAZOVANJA get_obrazovanje()const{
        return sk.get_obrazovanje();
    }
    VRSTA_SKOLE get_skola()const{
        return sk.get_skola();
    }
    double get_prosek()const{
        return knjizica.get_prosek();
    }
    int get_god()const{
        return knjizica.get_god();
    }
    POZICIJA get_poz()const{
        return pozicija;
    }
    int get_odmor()const{
        return odmor;
    }
    int get_vestina()const{
        return vestina;
    }
    int get_znanje()const{
        return znanje;
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
        if(odmor < 100 && pozicija == KOD_KUCE){
            odmor += satiSna*10;

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
    bool polozi_god(){
        if(pozicija == SKOLA && znanje > 60){

            if(60 < znanje && znanje < 71 && knjizica.get_god() < 4){
                knjizica.set_prosek(knjizica.get_prosek() + 2/65);
                knjizica.set_god(knjizica.get_god()+1);
                return true;
            }
            if(70 < znanje && znanje < 81 && knjizica.get_god() < 4){
                 knjizica.set_prosek(knjizica.get_prosek() + 2/65);
                 knjizica.set_god(knjizica.get_god()+1);
                 return true;
            }
            if(80 < znanje && znanje < 91 && knjizica.get_god() < 4){
                 knjizica.set_prosek(knjizica.get_prosek() + 2/65);
                 knjizica.set_god(knjizica.get_god()+1);
                 return true;
            }
            if(90 < znanje && znanje < 101 && knjizica.get_god() < 4){
                 knjizica.set_prosek(knjizica.get_prosek() + 2/65);
                 knjizica.set_god(knjizica.get_god()+1);
                 return true;
            }


        }
        return false;
    }

    bool maturiraj(){

        if(pozicija == SKOLA && sk.get_obrazovanje() == knjizica.get_god()){
            int a = rand()%5 + 1;
            if(a > 1){
                    cout<<"polozio sa ocenom:"<<a<<endl;
                return true;
            }
        }
        return false;
    }

};
void ispisi_ucenik(const Ucenik &u){
    cout<<"godina:"<<u.get_god()<<endl;
    cout<<"obrazovanje:";
    switch(u.get_obrazovanje()){
    case 1:
        cout<<"trogodisnje"<<endl;
        break;
    case 2:
        cout<<"cetvorogodisnje"<<endl;
        break;
    default:
        cout<<""<<endl;
        break;
    }
    cout<<"prosek:"<<u.get_prosek()<<endl;
    cout<<"skola:";
    switch(u.get_skola()){
    case 1:
        cout<<"strucna"<<endl;
        break;
    case 2:
        cout<<"gimnazija"<<endl;
        break;
    case 3:
        cout<<"umetnicja"<<endl;
        break;
    default:
        cout<<""<<endl;
        break;
    }
    cout<<"odmor:"<<u.get_odmor()<<endl;
    cout<<"vestina:"<<u.get_vestina()<<endl;
    cout<<"znanje:"<<u.get_znanje()<<endl;
    cout<<"pozicija:";
    switch(u.get_poz()){
    case 1:
        cout<<"kod kuce"<<endl;
        break;
    case 2:
        cout<<"skola"<<endl;
        break;
    case 3:
        cout<<"trening"<<endl;
        break;
    case 4:
        cout<<"biblioteka"<<endl;
        break;
    default:
        cout<<""<<endl;
        break;

        }
        cout<<"============"<<endl;

}
int meni(){
    int i;
    cout<<"1.idi kuci"<<endl;
    cout<<"2.idi na trening"<<endl;
    cout<<"3.idi u biblioteku"<<endl;
    cout<<"4.idi u ucionucu"<<endl;
    cout<<"5.spavaj"<<endl;
    cout<<"6.uci"<<endl;
    cout<<"7.treniraj"<<endl;
    cout<<"8.polozi god"<<endl;
    cout<<"9.maturiraj"<<endl;
    cout<<"10.vidi ucenika"<<endl;
    cout<<"11.zavrsi"<<endl;
    cin>>i;
    return i;
}
int main()
{
    Ucenik u;
    do{
        switch(meni()){
        case 1:
            if(u.idi_kuci() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 2:
            if(u.idi_na_trng() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 3:
            if(u.idi_u_biblioteku() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 4:
            if(u.idi_u_ucionica() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 5:
            if(u.spavaj(7) == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 6:
            if(u.uci() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 7:
            if(u.treniraj() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 8:
            if(u.polozi_god() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 9:
            if(u.maturiraj() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 10:
            ispisi_ucenik(u);
            break;
        case 11:
            return 0;
        default:
            cout<<"ne postoji operacija";
            break;
        }
    }while(1);
    return 0;
}
