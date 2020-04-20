#include <iostream>
using namespace std;

class Oblik{
protected:
    int a;
    int b;
public:
    Oblik(){
        a = 4;
        b = 5;
    }
    virtual ~Oblik(){}
    int get_a()const{
        return a;
    }
    int get_b()const{
        return b;
    }
    void set_a(const int aa){
        a = aa;

    }
    void set_b(const int bb){
        b = bb;
    }
    virtual void obim(){}         ///isto je
    virtual void povrsina() = 0;  /// =====
};
class Krug : public Oblik{
public:
    Krug(){
        a = 4;
        b = 5;
    }
    ~Krug(){}
    void obim(){
        float o = 2.0 * (float)a * 3.14;
        cout<<"obim kruga: "<<o<<endl;
    }
    void povrsina(){
        float p = (float)a * a * 3.14;
        cout<<"povrsina kruga: "<<p<<endl;
    }
};
class Kvadar : public Oblik{
public:
    Kvadar(){
        a = 4;
        b = 5;
    }
    ~Kvadar(){}
    void obim(){
        int o = 4 * a;
        cout<<"obim kvadra: "<<o<<endl;
    }
    void povrsina(){
        int p = a * a;
        cout<<"povrsina kvadra: "<<p<<endl;
    }
};
class Pravougaonik : public Oblik{
public:
    Pravougaonik(){
        a = 4;
        b = 5;
    }
    ~Pravougaonik(){}
    void obim(){
        int o = 2 * a + 2 * b;
        cout<<"obim pravougaonika: "<<o<<endl;
    }
    void povrsina(){
        int p = a * b;
        cout<<"povrsina pravougaonika: "<<p<<endl;
    }
};
class Zivotinja{
public:
    virtual void pricaj() = 0;
};

class Pas : public Zivotinja{
public:
    void pricaj(){
        cout<<" pas kaze: wowowowowow"<<endl;
    }
};

class Macka : public Zivotinja{
public:
    void pricaj(){
        cout<<" macka kaze: Mjauuuuu"<< endl;
    }
};

class Krava : public Zivotinja{
public:
    void pricaj(){
        cout<<" krava kaze: Mmuuuuu"<<endl;
    }
};
class Oblik1{
	public:
		virtual void obim() = 0;
		virtual void povrsina() = 0;
};
class Pravougaonik1 : public Oblik1{
private:
    int a;
    int b;
public:
    int get_a()const{
        return a;
    }
    int get_b()const{
        return b;
    }
    void set_a(const int aa){
        a = aa;
    }
    void set_b(const int bb){
        b = bb;
    }
    Pravougaonik1(){
        this->a = 4;
        this->b = 5;
    }
    Pravougaonik1(const int aa,const int bb){
        this->a = aa;
        this->b = bb;
    }
    void obim(){
        int o = 2 * a + 2 * b;
        cout<<"Obim pravougaonika: "<<o<<endl;
    }
    void povrsina(){
        int p = a * b;
        cout<<"Povrsina pravougaonika: "<<p<<endl;
    }
};
class Krug1 : public Oblik1{
private:
    int r;
public:
    Krug1(int rr){
        this->r = rr;
    }
    int get_r()const{
        return r;
    }
    void set_r(const int rr){
        r = rr;
    }
    void obim()
    {
        float o = 2.0 * 3.14 * (float)r;
        cout<<"Obim kruga: "<<o<<endl;
    }
    void povrsina()
    {
        float p = (float)r * r * 3.14;
        cout<<"Povrsina kruga: "<<p<<endl;
    }
};
int main()
{
    cout<<"OBLIK ZAD."<<endl;
	Krug q;
	Kvadar k;
	Pravougaonik p;

	Oblik *oq = &q;
	Oblik *ok = &k;
	Oblik *op = &p;

	oq->set_a(5);
	oq->set_b(1);
	ok->set_a(6);
	ok->set_b(10);
	op->set_a(4);
	op->set_b(1);

	cout<<"KRUG"<<endl;
	q.obim();
	q.povrsina();
	cout<<"KVADAR"<<endl;
	k.obim();
	k.povrsina();
	cout<<"PRAAVOUGAONIK"<<endl;
	p.obim();
	p.povrsina();

    cout<<"ZIVOTINJE ZAD."<<endl;
    Pas peso;
    Macka maca;
    Krava krava;

    Zivotinja *zpeso = &peso;
    Zivotinja *zmaca = &maca;
    Zivotinja *zkrava = &krava;

    zpeso->pricaj();
    zmaca->pricaj();
    zkrava->pricaj();

    cout<<"OBLICI TRECI PRIMER"<<endl;
    Pravougaonik1 p1(4,5);
    Krug1 k1(4);
    Oblik1 *op1 = &p1;
    Oblik1 *ok1 = &k1;
    op1->obim();
    op1->povrsina();
    ok1->obim();
    ok1->povrsina();
 	return 0;
}

