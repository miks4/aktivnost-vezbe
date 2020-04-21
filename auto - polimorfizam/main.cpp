#include <iostream>

using namespace std;

enum TIP_GUME{LETNJE = 1,ZIMSKE};

class Vozilo{
protected:
    int brzina;
public:
    Vozilo(int brbrbrbrb){
        brzina = brbrbrbrb;
    }
    virtual ~Vozilo(){}
    void set_br(const int brr){
        brzina = brr;
    }
    int get_br()const{
        return brzina;
    }
    virtual void ispis() = 0;
};

class Auto : public Vozilo{
private:
    TIP_GUME gume;
public:
    Auto(TIP_GUME gum,int brrr) : Vozilo(60){
        gume = gum;
    }
    ~Auto(){}
    int get_br()const{
        return brzina;
    }
    void ispis(){
        switch(gume){
        case 1:
            cout<<"tip gume: letnje"<<endl;
            break;
        case 2:
            cout<<"tip gume: zimske"<<endl;
            break;
        default:
            cout<<"nepostojeci tip"<<endl;
            break;
        }
    }
};

class Avion : public Vozilo{
private:
    int visina;
public:
    Avion(int v,int b) : Vozilo(100){
        visina = v;
    }
    ~Avion(){}
    void set_visina(const int v){
        visina = v;
    }
    int get_br()const{
        return brzina;
    }
    void ispis(){
        cout<<"avion se nalazi na visini od:"<<visina<<endl;
    }
};
int main()
{
    Auto a(LETNJE,60);
    Avion av(50,100);
    Vozilo *va = &a;
    Vozilo *vav = &av;
    cout<<"automobil"<<endl;
    va->ispis();
    cout<<"avion"<<endl;
    vav->ispis();
    return 0;
}
