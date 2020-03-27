#include <iostream>

using namespace std;
enum VRSTA_MESA{SVINJETINA = 1,JUNJETINA,PILETINA,BEZ_MESA};
enum PRILOG{RIZA,POMFRIT,PASULJ,TESTENINA,NEMA_PRILOGA};
enum STANJE{POCETAK_ODABIRA,ODABRANO_MESO,ODABRAN_PRILOG,SPREMAN,ZAGOREO};

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
int main()
{
    Meso m;
    ispisi_meso(m);
    Meso m1();
    Meso m2(m);
    cout<<"=========="<<endl;
    Prilog p;
    ispisi_prilog(p);
    Prilog p1();
    Prilog p2(p);
    cout<<"========"<<endl;
    Obrok o;
    Obrok o1();
    Obrok o2(o);
    return 0;
}
