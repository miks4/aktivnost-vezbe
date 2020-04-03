#include <iostream>
#include <cmath>

using namespace std;
enum TIP_MREZE{DUBOKA = 1,OBICNA};
enum STANJE_TESTA{START = 1,PROCESIRANJE,OPTIMIZACIJA,KRAJ};
class NeuronsskaMreza{
private:
    TIP_MREZE tip;
    int brSkrivenihSlojeva;
    int brNeuronaPoSloju;
public:
    NeuronsskaMreza(){
        brSkrivenihSlojeva = 0;
        brNeuronaPoSloju = 0;
    }
        NeuronsskaMreza(int bss,int bnps){
            if(bss<0){
                brSkrivenihSlojeva = 0;
            }
            if(bnps<0){
                brNeuronaPoSloju = 0;
            }
            brSkrivenihSlojeva = bss;
            brNeuronaPoSloju = bnps;
        }
        TIP_MREZE get_tip()const{
            if(brNeuronaPoSloju >= 1000){
                return DUBOKA;
            }
            return OBICNA;
        }
        int get_skriveniSloj()const{
            return brSkrivenihSlojeva;
        }
        int get_neuroniPoSloju()const{
            return brNeuronaPoSloju;
        }
        void set_skrivenisloj(const int sss){
            brSkrivenihSlojeva = sss;
        }
        void set_neuroniPoSloju(const int nnn){
            brNeuronaPoSloju = nnn;
        }
        void dodajSkriveniSloj(){
           brSkrivenihSlojeva += 1;
           cout<<"broj skrivenih slojeva:"<<brSkrivenihSlojeva<<endl;
        }
        void dodaj_neuron(){
            brNeuronaPoSloju += 1;
            cout<<"br, neurona po sloju:"<<brNeuronaPoSloju<<endl;
        }
        double Izracunaj_uspeh()const{
            double uspeh = 1 + 1/log(brSkrivenihSlojeva * brNeuronaPoSloju);
           return uspeh;
        }

};
class Test{
private:
    NeuronsskaMreza nm;
    double zeljeniProcenatUspesnosti;
    int brOptimizacija;
    STANJE_TESTA stanje;
public:
    Test(){
        zeljeniProcenatUspesnosti = 0.85;
        brOptimizacija = 0;
        stanje = START;
    }
    Test(int zpu,int bo,STANJE_TESTA st,int bs,int bn) : nm(3,200){
        stanje = st;
        brOptimizacija = bo;
        if(0 > zeljeniProcenatUspesnosti || zeljeniProcenatUspesnosti > 1){
            zeljeniProcenatUspesnosti = 0.85;
        }
        else{
            zeljeniProcenatUspesnosti = zpu;
        }
    }
    STANJE_TESTA get_stanje()const{
        return stanje;
    }
    double get_procenat()const{
        return zeljeniProcenatUspesnosti;
    }
    int get_bo()const{
        return brOptimizacija;
    }
    int get_brslojeva()const{
        return nm.get_skriveniSloj();
    }
    int get_brneurona()const{
        return nm.get_neuroniPoSloju();
    }
    TIP_MREZE get_tiip()const{
        return nm.get_tip();
    }
    bool procesiraj(){
        if((stanje == START || stanje == OPTIMIZACIJA) && zeljeniProcenatUspesnosti > nm.Izracunaj_uspeh()){
            stanje = PROCESIRANJE;
            return true;
        }
        if((stanje == START || stanje == OPTIMIZACIJA) && zeljeniProcenatUspesnosti <= nm.Izracunaj_uspeh()){
            stanje = KRAJ;
            cout<<"broj optimizacija:"<<brOptimizacija<<endl;
            cout<<"zeljena uspesnost:"<<zeljeniProcenatUspesnosti<<endl;
            cout<<"tacnost:"<<nm.Izracunaj_uspeh()<<endl;
            cout<<"uspesno izvrsen!"<<endl;
            return true;
        }
        return false;
    }
    bool potrebnoOptimizovati(){
        if(stanje == PROCESIRANJE){
            stanje = OPTIMIZACIJA;
            return true;
        }
        return false;
    }
    bool optimizuj(){
        if(stanje == OPTIMIZACIJA){
            nm.set_neuroniPoSloju(nm.get_neuroniPoSloju()+1);
        nm.set_skrivenisloj(nm.get_skriveniSloj()+1);
            return true;
        }
    }
    double izracunajUspeh()const{
        return nm.Izracunaj_uspeh();
    }

};
void ispisiTest(const Test &t){
    cout<<"stanje testa:";
    switch(t.get_stanje()){
    case 1:
        cout<<"start"<<endl;
        break;
    case 2:
        cout<<"procesiranje"<<endl;
        break;
    case 3:
        cout<<"optimizacija"<<endl;
        break;
    case 4:
        cout<<"kraj"<<endl;
        break;
    default:
        break;
    }
    cout<<"tip neuronske mreze:";
    switch(t.get_tiip()){
    case 1:
        cout<<"duboku"<<endl;
        break;
    case 2:
        cout<<"obicni"<<endl;
        break;
    default:
        break;
    }
    cout<<"tacnost:"<<t.izracunajUspeh()<<endl;

}
int meni(){
    int i;
    cout<<"1.procesiraj"<<endl;
    cout<<"2.potrebno optimizovati"<<endl;
    cout<<"3.optimizuj"<<endl;
    cout<<"4.vidi test"<<endl;
    cout<<"5.kraj"<<endl;
    cin>>i;
    return i;
}
int main()
{
    Test t;
    do{
        switch(meni()){
        case 1:
            if(t.procesiraj()==true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 2:
            if(t.potrebnoOptimizovati()==true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 3:
            if(t.optimizuj()==true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseni"<<endl;
            }
            break;
        case 4:
            ispisiTest(t);
            break;
        case 5:
            return 0;
        default:
            break;
        }

    }while(1);
    return 0;
}
