#include <iostream>
#include "dinString.hpp"
using namespace std;

class Osoba{
protected:
    DinString ime,prezime;
public:
    Osoba(const char* ime1 = "milos",const char* prezime1 = "milosevic") : ime(ime1) , prezime(prezime1){}
    Osoba(const DinString &pime1,const DinString &pprezime1) : ime(pime1) , prezime(pprezime1){}
    Osoba(DinString &imee){
        ime = imee;
        prezime = prezime;
    }
    Osoba(const Osoba &kopija){
        ime = kopija.ime;
        prezime = kopija.prezime;
    }
    void ispis()const{
        cout<<"ime:"<<ime<<endl<<"prezime:"<<prezime<<endl;
    }

};
class Student : public Osoba{
protected:
    int brIndeksa;
public:
    Student(const char* ime1 = "milos",const char* prezime1 = "milosevic",int br = 0) : Osoba(ime1,prezime1){
        brIndeksa = br;
    }
    Student(const DinString &pime1,const DinString &pprezime1,int br) : Osoba(pime1,pprezime1){
        brIndeksa = br;
    }
    Student(const Osoba &kopija,int br) : Osoba(kopija) , brIndeksa(br) {}
    Student(const Student &s) : Osoba((Osoba)s){
        brIndeksa = s.brIndeksa;
    }
    void ispis()const{
        Osoba::ispis();
        cout<<"broj indeks:"<<brIndeksa<<endl;
    }
};
class PHstudent : public Student{
private:
    float prosecnaOcena;
public:
    PHstudent(const char* ime1 = "milos",const char* prezime1 = "milosevic",int br = 0,float po = 0) : Student(ime1,prezime1,br){
        prosecnaOcena = po;
    }
    PHstudent(const DinString &pime1,const DinString &pprezime1,int br,float po) : Student(pime1,pprezime1,br){
        prosecnaOcena = po;
    }
    PHstudent(const Osoba &osoba,int br,float po) : Student(osoba,br) , prosecnaOcena(po){}
    PHstudent(const Student &student,float po) : Student(student) , prosecnaOcena(po){}
    PHstudent(const PHstudent &phstudent) : Student((Student)phstudent){
        prosecnaOcena = phstudent.prosecnaOcena;
    }
    void ispis()const{
        Student::ispis();
        cout<<"prosecna ocena:"<<prosecnaOcena<<endl;
    }
};
int main()
{





    return 0;
}
