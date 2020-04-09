#include <iostream>

using namespace std;
class Telo{
public:
     virtual float povrsina() = 0;
     virtual float zapremina() = 0;
     void ispisInf();
};
class Kvadar : public Telo{
protected:
    float a;
    float b;
    float c;
public:
    Kvadar(){
        a = 3;
        b = 4;
        c = 5;
    }
    Kvadar(float aa,float bb,float cc){
            a = aa;
            b = bb;
            c = cc;
    }
    Kvadar(const Kvadar &kopija){
        a = kopija.a;
        b = kopija.b;
        c = kopija.c;
    }
    ~Kvadar(){};
    float get_a()const{
        return a;
    }
    float get_b()const{
        return b;
    }
    float get_c()const{
        return c;
    }
    float povrsina(){
        float p = 2*(a*b + a*c + b*c);
        return p;
    }
    float zapremina(){
        float v = a * b * c;
        return v;
    }
    void ispisInf(){
        cout<<"stranica a:"<<a<<endl<<"stranica b:"<<b<<endl<<"stranica c:"<<c<<endl;
        cout<<"povrsina kvadra:"<<povrsina()<<endl<<"zapremina:"<<zapremina()<<endl;
    }
};
class Piramida : public Telo{
protected:
    float d;
    float h;
public:
    Piramida(){
        d = 4;
        h = 5;
    }
    Piramida(float apap,float vbcvbc){
        d = apap;
        h = vbcvbc;
    }
    Piramida(const Piramida &kopija){
        d = kopija.d;
        h = kopija.h;
    }
    ~Piramida(){};
    float get_d()const{
        return d;
    }
    float get_h()const{
        return h;
    }
    float povrsina(){
        float p = d * d + 2 *h;
        return p;
    }
    float zapremina(){
        float v = (d * d * h)/3;
        return v;
    }
    void ispisInf(){
        cout<<"duzina stranice:"<<d<<endl<<"vrednost visine:"<<h<<endl;
        cout<<"povrsina piramide:"<<povrsina()<<endl<<"zapremina:"<<zapremina()<<endl;
    }
};
class Kocka : public Kvadar{
public:
    Kocka() : Kvadar(3,3,3){}
    Kocka(float a) : Kvadar(a,a,a){}
    Kocka(const Kocka &kopija) : Kvadar(kopija){}
    ~Kocka(){}
    float povrsina(){
        float p = a * a * 6;
        return p;
    }
    float zapremina(){
        float v = a * 3;
        return v;
    }
    void ispisInf(){
        cout<<"stranica kocke:"<<a<<endl;
        cout<<"povrsina kocke:"<<povrsina()<<endl<<"zapremina kocke:"<<zapremina()<<endl;
    }
};
class JSPiramida : public Piramida{
public:
    JSPiramida() : Piramida(4,4){}
    JSPiramida(float d,float h) : Piramida(d,h){}
    JSPiramida(const JSPiramida &kopija) : Piramida(kopija){}
    ~JSPiramida(){}
    float povrsina(){
        float p = d * d + 2 * h;
        return p;
    }
    float zapremina(){
        float v =  (d * d * h) / 3;
        return v;
    }
    void ispisInf(){
        cout<<"visina:"<<h<<endl<<"stranica:"<<d<<endl;
        cout<<"povrsina jspiramide:"<<povrsina()<<endl<<"zapremina jspiramide:"<<zapremina()<<endl;
    }
};
class SpecTelo : public Telo{
private:
    Kocka k;
    JSPiramida jp;
public:
    SpecTelo() : k() , jp(){}
    SpecTelo(float strKocke,float stranicaP,float visinaP) : k(strKocke) , jp(stranicaP,visinaP){}
    SpecTelo(const SpecTelo &kopija) : k(kopija.k),jp(kopija.jp){}
    ~SpecTelo(){}
    float povrsina(){
        float p = k.povrsina() + 2 * jp.povrsina();
        return p;
    }
    float zapremina(){
        float v = k.zapremina() + 2 * jp.zapremina();
        return v;
    }
    void ispisInf(){
        cout<<"povrsina spec. tela:"<<povrsina()<<endl<<"zapremina spec. tela:"<<zapremina()<<endl;
    }

};

int main()
{
    cout<<"KVADAR"<<endl;
    Kvadar q1();
    Kvadar q2(3,4,5);
    Kvadar q3(q2);
    Kvadar q;
    q.ispisInf();
    cout<<"============"<<endl;
    cout<<"PIRAMIDA"<<endl;
    Piramida p1();
    Piramida p2(4,5);
    Piramida p3(p2);
    Piramida p;
    p.ispisInf();
    cout<<"============"<<endl;
    cout<<"KOCKA"<<endl;
    Kocka k1();
    Kocka k2(3);
    Kocka k3(k2);
    Kocka k;
    k.ispisInf();
    cout<<"============"<<endl;
    cout<<"JEDNAKOSTTRANICNA PIRAMIDA"<<endl;
    JSPiramida j1();
    JSPiramida j2(4,4);
    JSPiramida j3(j2);
    JSPiramida j;
    j.ispisInf();
    cout<<"============"<<endl;
    cout<<"SPECIFICNO TELO"<<endl;
    SpecTelo spc1();
    SpecTelo spc2(3,4,4);
    SpecTelo spc3(spc2);
    SpecTelo spc;
    spc.ispisInf();
    cout<<"KRAJ"<<endl;



    return 0;
}
