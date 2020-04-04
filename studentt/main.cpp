#include <iostream>

using namespace std;
class Osoba{
protected:
    string ime;
    string prezime;
public:
    Osoba(){
        ime = "milos";
        prezime = "mrdja";
    }
    Osoba(string imee,string pree){
        ime = imee;
        prezime = pree;
    }
    Osoba(const Osoba &kopija){
        ime = kopija.ime;
        prezime = kopija.prezime;
    }
    void predstavi_se()const{
        cout<<"ime:"<<ime<<endl<<"prezime:"<<prezime<<endl;
    }

};

class Student : public Osoba{
protected:
    int br_indeksa;
public:
    Student() : Osoba("milos","mrdja"){
    br_indeksa = 1234;
    }
    Student(string i,string p,int br) : Osoba(ime,prezime) , br_indeksa(br){
        br_indeksa = br;
    }
    Student(const Student &kop,int br) : Osoba(kop.ime,kop.prezime) , br_indeksa(br) {
        br_indeksa = kop.br_indeksa;
    }

    void predstavi_se()const{
        cout<<"br. indeksa:"<<br_indeksa<<endl;
    }


};

class phStudent : public Student{
private:
    double prosecnaOcena;
public:
    phStudent() : Student("milos","mrdja",1234){
        prosecnaOcena = 9.9;
    }
    phStudent(string im,string prez,int br_,int po) : Student(ime,prezime,br_indeksa) , prosecnaOcena(po){
        prosecnaOcena = po;
    }
    phStudent(const phStudent &k,int po) : Student(k.ime,k.prezime,k.br_indeksa) , prosecnaOcena(po){
        prosecnaOcena = k.prosecnaOcena;
    }
    void predstavi_se()const{
    cout<<"prosecna ocena:"<<prosecnaOcena<<endl;
    }
};
int main()
{
    Osoba o;
    o.predstavi_se();
    Student st;
    st.predstavi_se();
    phStudent ph;
    ph.predstavi_se();


    return 0;
}
