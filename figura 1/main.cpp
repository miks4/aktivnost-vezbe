#include <iostream>
#include <cmath>

using namespace std;

class Figura{
protected:
    double a;
    double b;
public:
    Figura(){
        a = 3;
        b = 4;
    }
    void set_a(const int aaa){
        a = aaa;
    }
    void set_b(const int bbb){
        b = bbb;
    }
    int get_A()const{
        return a;
    }
    int get_b()const{
        return b;
    }
    Figura(double aa,double bb){
        a = aa;
        b = bb;
    }
    Figura(const Figura &kopija){
        a = kopija.a;
        b = kopija.b;
    }
    void izracunaj_povrsinu();
    void obim();

};

class Pravougaonik : public Figura{
    public:
    Pravougaonik() : Figura(3,4){}
    Pravougaonik(double aa,double bb) : Figura(aa,bb){}
    Pravougaonik(const Pravougaonik &prav) : Figura(prav.a,prav.b){}
    void izracunaj_povrsinu(){
        double p = a *b;
        cout<<"povrsina pravougaonika:"<<p<<endl;
    }
    void obim(){
        double o = a+b;
        cout<<"obim pravougaonika:"<<o<<endl;
    }
};
class Elipsa : public Figura{
public:
    Elipsa() : Figura(3,4){}
    Elipsa(double aa,double bb) : Figura(aa,bb){}
    Elipsa(const Elipsa &prav) : Figura(prav.a,prav.b){}

    void izracunaj_povrsinu(){
        double x = a/2;
        double y = b/2;
        double pi = 3.14;
        double p = x*y*pi;
        cout<<"povrsina elipse:"<<p<<endl;
    }
    void obim(){
        double x = a/2;
        double y = b/2;
        double pi = 3.14;
        double o = pi *((3*x + 3*y) - sqrt((3*x + y)*(x + 3*y)));
        cout<<"obim elipse:"<<o<<endl;    }
};

int main()
{

    Pravougaonik pr;
    pr.izracunaj_povrsinu();
    pr.obim();
    Elipsa e;
    e.izracunaj_povrsinu();
    e.obim();
    return 0;
}
