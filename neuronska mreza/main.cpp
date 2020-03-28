#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
enum VRSTA_MESA{SVINJETINA = 1,JUNJETINA,PILETINA,BEZ_MESA};
enum PRILOG{RIZA = 1,POMFRIT,PASULJ,TESTENINA,NEMA_PRILOGA};
enum STANJE{POCETAK_ODABIRA = 1,ODABRANO_MESO,ODABRAN_PRILOG,SPREMAN,ZAGOREO};

class Meso{
    int gramaza;
    VRSTA_MESA vrsta;
public:
    Meso(){
        gramaza = 0;
        vrsta = BEZ_MESA;
    }
    Meso(const Meso &meso_za_kopiju){
        gramaza = meso_za_kopiju.gramaza;
        vrsta = meso_za_kopiju.vrsta;
    }
    int get_gramaza()const{

        if(0 < gramaza && gramaza < 1001){
            return gramaza;
        }
        return 0;
    }
    VRSTA_MESA get_vrsta()const{
        return vrsta;
    }
    void set_gramaza(const int gg){
        gramaza = gg;
    }
    void set_vrsta(const VRSTA_MESA vm){
        vrsta = vm;
    }

};

class Prilog{
private:
    PRILOG prilog;
public:
    Prilog(){
        prilog = NEMA_PRILOGA;
    }
    Prilog(const Prilog &kopija){
        prilog = kopija.prilog;
    }
    PRILOG get_prilog()const{
        return prilog;
    }

    void set_prilog(const PRILOG pp){
        prilog = pp;
    }


};

class Obrok{
private:
    Prilog odabran_prilog;
    Meso odabrano_meso;
    Meso odabrana_gramaza;
    STANJE stanje;
public:
    Obrok(){
        stanje = POCETAK_ODABIRA;
    }
    Obrok(const Obrok &kopija){
        stanje = kopija.stanje;
    }

    PRILOG get_Oprilog()const{
        return odabran_prilog.get_prilog();
    }

    VRSTA_MESA get_Omeso()const{

        return odabrano_meso.get_vrsta();
    }

    STANJE get_stanje()const{
        return stanje;
    }

    void set_Oprilog(const Prilog ppp){
        odabran_prilog.set_prilog(NEMA_PRILOGA);
    }

    bool odaberi_meso(){
        int i = rand()%1000 + 1;
        int a = rand()%4 + 1;
        if(0 < i && i < 1001 && 0 < a && a < 5){
                cout<<"odabrano meso:"<<endl;
                switch(a){
    case 1:
        cout<<"svinjetina"<<endl;
        break;
    case 2:
        cout<<"junjetina"<<endl;
        break;
    case 3:
        cout<<"piletina"<<endl;
        break;
    case 4:
        cout<<"nema mesa"<<endl;
        break;
    default:
        cout<<"greska"<<endl;
        break;

    }
            stanje = ODABRANO_MESO;
            return true;
        }
        return false;
    }
    bool odaberi_prilog(){
        int i = rand()%5 + 1;
        if(stanje == ODABRANO_MESO && 0 < i && i < 6){
            cout<<"odabran prilog:"<<endl;
                switch(i){
    case 1:
        cout<<"riza"<<endl;
        break;
    case 2:
        cout<<"pomfrit"<<endl;
        break;
    case 3:
        cout<<"pasulj"<<endl;
        break;
    case 4:
        cout<<"testenina"<<endl;
        break;
    case 5:
        cout<<"nema priloga"<<endl;
        break;
    default:
        cout<<"greska"<<endl;
        break;

    }
                stanje = ODABRAN_PRILOG;
            return true;
        }
        return false;
    }
    bool spremi(){
        int i = rand()%100 + 1;
        if(0 < i && i < 91){
                stanje = SPREMAN;
            return true;
        }
        stanje = ZAGOREO;
        return false;
    }



};
void ispisi_meso(const Meso &m){
    cout<<"meso u gramima:"<<m.get_gramaza()<<endl;
    cout<<"vrsta mesa:";
    switch(m.get_vrsta()){
    case 1:
        cout<<"svinjetina"<<endl;
        break;
    case 2:
        cout<<"junjetina"<<endl;
        break;
    case 3:
        cout<<"piletina"<<endl;
        break;
    case 4:
        cout<<"nema mesa"<<endl;
        break;
    default:
        cout<<"greska"<<endl;
        break;

    }
}

void ispisi_prilog(const Prilog &p){
    cout<<"prilog:";
    switch(p.get_prilog()){
    case 1:
        cout<<"riza"<<endl;
        break;
    case 2:
        cout<<"pomfrit"<<endl;
        break;
    case 3:
        cout<<"pasulj"<<endl;
        break;
    case 4:
        cout<<"testenina"<<endl;
        break;
    case 5:
        cout<<"nema priloga"<<endl;
        break;
    default:
        cout<<"greska"<<endl;
        break;

    }
}
void ispis_obrok(const Obrok &o){
    cout<<"odabrano meso:"<<o.get_Omeso()<<endl;
    cout<<"odabran prilog:"<<o.get_Oprilog()<<endl;
    cout<<"stanje obroka:";
    switch(o.get_stanje()){
    case 1:
        cout<<"pocetak odabira"<<endl;
        break;
    case 2:
        cout<<"odabrano meso"<<endl;
        break;
    case 3:
        cout<<"odabran prilog"<<endl;
        break;
    case 4:
        cout<<"spreman"<<endl;
        break;
    case 5:
        cout<<"zagoreo"<<endl;
        break;
    default:
        cout<<"ne postoji"<<endl;
        break;
    }
}
int meni(){
    int i;
    cout<<"1.odaberi meso"<<endl;
    cout<<"2.odaberi prilog"<<endl;
    cout<<"3.spremi obrok"<<endl;
    cout<<"4.vidi prilog"<<endl;
    cout<<"5.vidi meso"<<endl;
    cout<<"6.vidi obrok"<<endl;
    cout<<"7.zavrsi"<<endl;
    cin>>i;
    return i;
}
int main()
{
    srand(time(NULL));
    Meso m;
    Meso m1();
    Meso m2(m);
    Prilog p;
    Prilog p1();
    Prilog p2(p);
    Obrok o;
    Obrok o1();
    Obrok o2(o);
    do{
        switch(meni()){
        case 1:
            if(o.odaberi_meso() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 2:
            if(o.odaberi_prilog() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 3:
            if(o.spremi() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 4:
            ispisi_prilog(p);
            break;
        case 5:
            ispisi_meso(m);
            break;
        case 6:
            ispis_obrok(o);
            break;
        case 7:
            cout<<"zavrseno"<<endl;
            return 0;
        default:
            cout<<"ne postoji"<<endl;
            break;
        }
    }while(1);
    return 0;
}
