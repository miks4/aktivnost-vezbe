#include <iostream>
#include <cmath>

using namespace std;
class Figura{
protected:
    double a;
    double b;
public:
    Figura(){
        a=3;
        b=4;
    }
    Figura(double aa,double bb){
        a = aa;
        b = bb;
    }
    Figura(const Figura &kopija){
        a = kopija.a;
        b = kopija.b;
    }
    void set_a(const double aa){
        a = aa;
    }
    void set_b(const double bb){
        b = bb;
    }
    double get_a()const{
        return a;
    }
    double get_b()const{
        return b;
    }
    double povrsina();
    double obim();
};
class Pravougaonik : public Figura{
public:
    Pravougaonik(){
        a = 3;
        b = 4;
    }
    Pravougaonik(double aa,double bb){
        a = aa;
        b = bb;
    }
    Pravougaonik(const Pravougaonik &kopija){
        a = kopija.a;
        b = kopija.b;
    }
    double povrsina(){
        double p = a*b;
        return p;
    }
    double obim(){
        double o = 2 * a + 2 * b;
        return o;
    }

};
class Elipisa : public Figura{
protected:
    double x;
    double y;
public:
    Elipisa(){
    a = 3;
    b = 4;
    x = a/2;
    y = b/2;
    }
    Elipisa(double aa,double bb,double xx,double yy) : Figura(aa,bb){
        x = xx;
        y = yy;
    }
    Elipisa(const Elipisa &kopija) : Figura(kopija.a,kopija.b){
        x = kopija.x;
        y = kopija.y;
    }
    void set_x(const double xx){
        x = xx;
    }
    void set_y(const double yy){
        y = yy;
    }
    double get_x()const{
        return x;
    }
    double get_y()const{
        return y;
    }
    double povrsina(){
        double p = x*y*3.14;
        return p;
    }
    double obim(){
        double o = 3.14*(3*(x+y)-sqrt((3*x+y)*(x+3*y)));
        return o;
    }
};
class Krug : public Elipisa{
protected:
    double r;
public:
    Krug() : Elipisa(3,3,3,3){
        r = 3;
    }
    Krug(double rr) : Elipisa(a,b,x,y){
        r = rr;
    }
    Krug(const Krug &kopija) : Elipisa(kopija.a,kopija.b,kopija.x,kopija.y){
        r = kopija.r;
    }
    void set_r(const double rr){
        r = rr;
    }
    double get_r()const{
        return r;
    }
    double povrsina(){
        double p = r * 2 * 3.14;
        return p;
    }
    double obim(){
        double o = 2 * r* 3.14;
        return o;
    }
};
class Kvadrat : public Pravougaonik{
public:
    Kvadrat(){
        a = 3;
        b = 3;
    }
    Kvadrat(int aa){
        a = aa;
        b = aa;
    }
    Kvadrat(const Kvadrat &kopija){
        a = kopija.a;
        b = kopija.b;
    }
    double povrsina(){
        double p = a * a;
        return p;
    }
    double obim(){
        double o = 4 * a;
        return o;
    }
};
int main()
{
    Figura f;

    Pravougaonik pp1();
    Pravougaonik pp2(3,4);
    Pravougaonik pp3(pp2);
    Pravougaonik pp;
    cout<<"PRAVOUGAONIK"<<endl;
    cout<<"vrednost a:"<<pp.get_a()<<endl;
    cout<<"vrednostt b:"<<pp.get_b()<<endl;
    pp.set_a(3);
    pp.set_b(4);
    cout<<"obim:"<<pp.obim()<<endl;
    cout<<"povrsina:"<<pp.povrsina()<<endl;

    cout<<"=================="<<endl;

    Elipisa e1();
    Elipisa e2(3,4,1.5,2);
    Elipisa e3(e2);
    Elipisa e;
    cout<<"ELIPSA"<<endl;
    cout<<"vrednosr a:"<<e.get_a()<<endl;
    cout<<"vrednost b:"<<e.get_b()<<endl;
    cout<<"vrednost x:"<<e.get_x()<<endl;
    cout<<"vrednost y:"<<e.get_y()<<endl;
    cout<<"povrsina:"<<e.povrsina()<<endl;
    cout<<"obim:"<<e.obim()<<endl;

    cout<<"=================="<<endl;

    Krug q1();
    Krug q2(3);
    Krug q3(q2);
    Krug q;
    cout<<"KRUG"<<endl;
    cout<<"poluprecnik:"<<q.get_r()<<endl;
    cout<<"povrsina:"<<q.povrsina()<<endl;
    cout<<"obim:"<<q.obim()<<endl;

    cout<<"=================="<<endl;

    Kvadrat k1();
    Kvadrat k2(3);
    Kvadrat k3(k2);
    Kvadrat k;
    cout<<"KVADRAT"<<endl;
    cout<<"stranica:"<<k.get_b()<<endl;
    cout<<"povrsina:"<<k.povrsina()<<endl;
    cout<<"obim:"<<k.obim()<<endl;

    cout<<"=================="<<endl;

    return 0;
}
