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
    Pravougaonik(double aa,double bb,int ii) : Figura(aa,bb){}
    Pravougaonik(const Pravougaonik &kopija) : Figura(kopija.a,kopija.b){}
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
        cout<<"obim elipse:"<<o<<endl;
           }
};
class Oblik{
protected:
    Pravougaonik a;
    Elipsa b;
public:
    Oblik() : a(3,4),b(3,4){}
    Oblik(int aa,int bb,int cc,int dd) : a(aa,bb) , b(cc,dd){}
    Oblik(const Oblik &kopija) : a(kopija.a.get_A(),kopija.a.get_b()) , b(kopija.b.get_A(),kopija.b.get_b()){}

    void povrsina(){
        double p = a.get_A() * a.get_b();
        cout<<"povrsina oblika je:"<<p<<endl;
    }
    void obimm(){
        double p = a.get_A() + a.get_b();
        cout<<"obim oblika je:"<<p<<endl;
    }
};

class PravilanOblik : public Oblik{
public:
    PravilanOblik() : Oblik(3,3,3,3){}
    PravilanOblik(int aa) : Oblik(aa,aa,aa,aa){}
    PravilanOblik(const PravilanOblik &po) : Oblik(po.a.get_A(),po.a.get_b(),po.b.get_A(),po.b.get_b()){}
    void povrsina(){
        double p = a.get_A() * a.get_b();
        cout<<"povrsina pravilnog oblika je:"<<p<<endl;
    }
    void obimm(){
        double p = a.get_A() + a.get_b();
        cout<<"obim pravilnog oblika:"<<p<<endl;
    }
};
int main()
{

    Pravougaonik pr;
    pr.izracunaj_povrsinu();
    pr.obim();

    Elipsa e;
    e.izracunaj_povrsinu();
    e.obim();

    Oblik o;
    o.povrsina();
    o.obimm();

    PravilanOblik po;
    po.povrsina();
    po.obimm();
    return 0;
}
