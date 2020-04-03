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
        double Izracunaj_uspeh(){
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
    Test(int zpu,int bo,STANJE_TESTA st,int bs,int bn) : nm(bs,bn){
        stanje = st;
        brOptimizacija = bo;
        if(0 > brOptimizacija && brOptimizacija > 1){
            brOptimizacija = 0.85;
        }
        else{
            brOptimizacija = bo;
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

};
int main()
{

    return 0;
}
