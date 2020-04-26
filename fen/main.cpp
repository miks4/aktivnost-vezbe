#include <iostream>
#include "dinstring.hpp"
using namespace std;
enum modovi{HLADNO = 1,TOPLO};
class ABS{
public:
    virtual int get_temperatura()const{};
    virtual void set_temperatura(int t)const{};
};
class Grejac : public ABS{
protected:
    int temperatura;
public:
    Grejac(){
        temperatura = 0;
    }
    Grejac(int temp){
        if(temp < 0){temperatura = 0;}
        else if(temp > 100){temperatura = 100;}
        else{
            temperatura = temp;
        }
    }
    Grejac(const Grejac &kopija){
        temperatura = kopija.temperatura;
    }
    int get_temperatura()const{
        return temperatura;
    }
    void set_temperatura(int t){
        if(t < 0){temperatura = 0;}
        else if(t > 100){temperatura = 100;}
        else{
            temperatura = t;
        }
    }

};
class Fen{
protected:
    DinString marka;
    modovi mod;
    Grejac grejac;
public:
    Fen() : grejac()  , mod(HLADNO){marka = "philips";}
    Fen(DinString m,modovi mo) : marka(m){
        mod = mo;
        if(mod == TOPLO){
               grejac.set_temperatura(1);
        }
        else{
            grejac.set_temperatura(0);
        }
    }
    Fen(const Fen &a) : marka(a.marka) , mod(a.mod) , grejac(a.grejac){}
    DinString get_marka()const{
        return marka;
    }

    modovi get_mod()const{
        return mod;
    }
    Grejac get_grejac()const{
        return grejac;
    }
    void set_mod(const modovi m){
        mod = m;
    }
    void set_grejac(const int g){
        if(grejac.get_temperatura() >= 1 && grejac.get_temperatura() <= 100){
            grejac.set_temperatura(g);
        }
        else{
            grejac.set_temperatura(0);
        }
    }
    void set_marka(const DinString d){
        marka = d;
    }
    friend ostream& operator<<(ostream& izlaz,const Fen &f){
        Grejac pom = f.get_grejac();
        DinString mod2;
        if(f.get_mod() == HLADNO)
            mod2 = "HLADNO";
        else
            mod2 = "TOPLO";
        izlaz<<f.get_marka()<<" "<<mod2<<" "<<pom.get_temperatura()<<endl;
        return izlaz;
    }
    Fen& operator =(const Fen &f){
        grejac=f.get_grejac();
        marka=f.get_marka();
        mod=f.get_mod();
        return *this;
    }

};
int main()
{
    Grejac g1();
    Grejac g2(5);
    Grejac g3(g2);
    cout<<g2.get_temperatura()<<endl<<g3.get_temperatura()<<endl;
    Fen f();
    Fen f1("philips", HLADNO);
    Fen f3("gorenje",TOPLO);
    Fen f2(f1);
    cout<<f<<endl<<f1<<endl<<f2<<endl<<f3<<endl;
    f3 = f2;
    cout<<f1<<endl<<f2<<endl<<f3<<endl;
    f1.set_grejac(0);
    f1.set_marka("gorenje");
    f1.set_mod(HLADNO);
    cout<<f1;
    return 0;
}
