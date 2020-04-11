#include <iostream>

using namespace std;
class DinString{
private:
    int duzina;
    char *text;
public:
    DinString();
    DinString(const char[]);
    DinString(const DinString &kopija);
    ~DinString(){}

    int lenght() const;

    char& operator[] (int);
    char operator[] (int)const;

    DinString operator=(const DinString& kopija);
    DinString operator+=(const DinString& kopija);

    friend bool operator==(const DinString&,const DinString&);
    friend bool operator!=(const DinString&,const DinString&);

    friend DinString operator+(const DinString&,const DinString&);

    friend ostream& operator<<(ostream&,const DinString);
};
class Tastatura{
protected:
    DinString proizvodjac;
    int brTastera;
public:

    Tastatura(const char* proizvodjac = "asus") : proizvodjac(proizvodjac){
        brTastera = 100;
    }
    Tastatura(const DinString& pro) : proizvodjac(pro){
        brTastera = 0;
    }
    Tastatura(const Tastatura& kopija,const Tastatura& kop):proizvodjac(kopija.proizvodjac){
        brTastera = kop.brTastera;
    }
    ~Tastatura(){}
    void set_tasteri(const int br){
        brTastera = br;
    }
    int get_tasteri()const{
        return brTastera;
    }
    void ispis(){
        cout<<"proizvodjac tastature:"<<proizvodjac<<endl<<"broj tastera:"<<brTastera<<endl;
    }
};
class gejmerskaTastatura : public Tastatura{
private:
    int brPritisaka;
public:
    gejmerskaTastatura(const char* s1 = "asus",int br = 0) : Tastatura(s1){
        brPritisaka = br;
    }
    gejmerskaTastatura(const gejmerskaTastatura& kopija) : Tastatura((Tastatura)kopija),brPritisaka(kopija.brPritisaka){}
    ~gejmerskaTastatura(){}
    void set_brPritisaka(const int br){
        brPritisaka = br;
    }
    int get_brPritisaka()const{
        return brPritisaka;
    }
    void ispis(){
        Tastatura::ispis();
        cout<<"broj pritisaka na tastaturi:"<<brPritisaka<<endl;
    }
    void pritisniTaster(){
        brPritisaka += 1;
    }
    void drziTaster(int sec){
        brPritisaka += sec;
    }
};
class numerickaTastatura : public Tastatura{
private:
    int brPritisakaBrojeva;
public:
    numerickaTastatura(const char* s1 = "asus",int br = 0) : Tastatura(s1){
        brPritisakaBrojeva = br;
    }
    numerickaTastatura(const numerickaTastatura& kopija) : Tastatura((Tastatura)kopija){
        brPritisakaBrojeva = kopija.brPritisakaBrojeva;
    }
    ~numerickaTastatura(){}
    void set_brPBrojeva(const int br){
        brPritisakaBrojeva = br;
    }
    int get_brPBrojeva()const{
        return brPritisakaBrojeva;
    }
    void ispis(){
        Tastatura::ispis();
        cout<<"broj pritisaka brojeva:"<<brPritisakaBrojeva<<endl;
    }
    bool pritisniBroj(){
        return true;
    }
    void pritisniTasterNum(bool pritisniBroj()){
        if(pritisniBroj() == true){
            brPritisakaBrojeva += 1;
        }
    }
    void drziTasterNum(int sec,bool pritisniBroj()){
        if(pritisniBroj() == true){
            brPritisakaBrojeva += sec;
        }
    }

};
int main()
{

    return 0;
}
