#include <iostream>

using namespace std;
class DinString{
private:
    int duzina;
    char *text;
public:
    DinString();
    DinString(const char[]);
    DinString(const DinString &);
    ~DinString(){}

    int lenght() const;

    char& operator[] (int);
    char operator[] (int)const;

    DinString operator=(const DinString&);
    DinString operator+=(const DinString&);

    friend bool operator==(const DinString&,const DinString&);
    friend bool operator!=(const DinString&,const DinString&);

    friend DinString operator+(const DinString&,const DinString&);

    friend ostream& operator<<(ostream&,const DinString);
};
class Alat{
protected:
    DinString serijskiBr,proizvodjac;
public:
    Alat(const char* serija = "1234",const char* pro = "cacak") : serijskiBr(serija),proizvodjac(pro){}
    Alat(const DinString &s,const DinString &b) : serijskiBr(s),proizvodjac(b){}
    Alat(const Alat &kopija) : serijskiBr(kopija.serijskiBr) , proizvodjac(kopija.proizvodjac){}
    ~Alat(){}
    void ispis(){
        cout<<"proizvodjac alata:"<<proizvodjac<<endl<<"serijski broj:"<<serijskiBr<<endl;
    }

};
class Cekic : public Alat{
private:
    float tezina;
    int upotrebljivost;
public:
    Cekic(const char* serija = "123",const char* pro = "cacak",float t = 2,int u = 100) : Alat(serija,pro){
        tezina = t;
        upotrebljivost = u;
    }
    Cekic(const DinString &sserija,const DinString ppro,float tt,int uu) : Alat(sserija,ppro),tezina(tt),upotrebljivost(uu){}
    Cekic(const Alat &al,float ttt,int uuu) : Alat(al),tezina(ttt),upotrebljivost(uuu){}
    Cekic(const Cekic &kopija,const Cekic &kop) : Alat((Alat)kopija){
        tezina = kop.tezina;
        upotrebljivost = kop.upotrebljivost;
    }
    ~Cekic(){}
    void set_tezina(const float t){
        tezina = t;
    }
    void set_upotrebljivost(const int u){
        if(u > 0){
            upotrebljivost = u;
        }
        else{
            cout<<"niste uneli validnu upotrebljivost"<<endl;
        }
    }
    float get_tezina()const{
        return tezina;
    }
    int get_upotrebljivost()const{
        return upotrebljivost;
    }
    void ispis(){
        Alat::ispis();
        cout<<"tezina cekica:"<<tezina<<endl<<"upotrebljivost"<<upotrebljivost<<endl;
    }
    bool upotrebi(){
        upotrebljivost -= 1;
        if(upotrebljivost == 0){
            upotrebi();
            return false;
        }
        return true;
    }
};
class Testera : public Alat{
private:
    double otupljenost;
public:
    Testera(const char* s1 = "124",const char* s2 = "cacak",double o = 0.05) : Alat(s1,s2) , otupljenost(o){}
    Testera(const DinString &ds1,const DinString &ds2,double oo) : Alat(ds1,ds2) , otupljenost(oo){}
    Testera(const Alat &al,double ooo) : Alat(al) , otupljenost(ooo){}
    Testera(const Testera &kopija,const Testera &kop) : Alat((Alat)kopija) , otupljenost(kop.otupljenost){}
    ~Testera(){}
    void set_otupljenost(const double o){
        otupljenost = o;
    }
    double get_otupljenost()const{
        return otupljenost;
    }
    void ispis(){
        Alat::ispis();
        cout<<"otupljenost testere:"<<otupljenost<<endl;
    }
    bool upotrebi(){
        otupljenost += 0.05;
        if(otupljenost > 1){
            return false;
        }
        return true;
    }
    bool naostri(){
        otupljenost -= 0.05;
        if(otupljenost < 0){
            return false;
        }
        return true;
    }
};
int main()
{
    return 0;
}
