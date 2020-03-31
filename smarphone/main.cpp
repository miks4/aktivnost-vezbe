#include <iostream>

using namespace std;
enum VRSTA_OS{ANDROID = 1,IOS};
enum STANJE_SMARTPHONE{UKLJUCEN = 1,ISKLJUCEN,STANDBY,AZURIRA_SE};
class OSistem{
private:
    VRSTA_OS vrsta_os;
    int verzija;
public:
    OSistem(){
        vrsta_os = ANDROID;
        verzija = 1;
    }
    OSistem(VRSTA_OS vr,int v){
        vrsta_os = vr;
        verzija = v;
    }
    VRSTA_OS get_vrsta()const{
        return vrsta_os;
    }
    int get_verzija()const{
        return verzija;
    }
    void set_verzija(const int vv){
        verzija = vv;
    }


};

class Smartphone{
private:
    OSistem op_s;
    STANJE_SMARTPHONE stanje;
    int DowlandProgress;
public:
    Smartphone(){
        stanje = ISKLJUCEN;
        DowlandProgress = -1;
    }
    Smartphone(STANJE_SMARTPHONE st,int dp){
        stanje = st;
        DowlandProgress = dp;
    }
    STANJE_SMARTPHONE get_stanje()const{
        return stanje;
    }
    VRSTA_OS get_vrsta()const{
            return op_s.get_vrsta();
    }
    int get_verzija()const{
        return op_s.get_verzija();
    }
    bool turnOn(){
        if(stanje == ISKLJUCEN && DowlandProgress == -1){
            stanje = UKLJUCEN;
            return true;
        }
        return false;
    }
    bool turn_of(){
        if(stanje == UKLJUCEN && DowlandProgress == -1){
            stanje = ISKLJUCEN;
            return true;
        }
        return false;
    }
    bool sleep(){
        if(stanje == UKLJUCEN && DowlandProgress == -1){
            stanje = STANDBY;
            return true;
        }
        return false;
    }
    bool wake_up(){
        if(stanje == STANDBY && DowlandProgress == -1){
                stanje = UKLJUCEN;
        return true;
        }
        return false;
    }
    bool finish_update(){
        if(stanje == AZURIRA_SE && DowlandProgress == 100){
            stanje = UKLJUCEN;
            DowlandProgress = -1;
            return true;
        }
        return false;
    }
    bool start_update(int nwn){
        stanje = AZURIRA_SE;
        DowlandProgress = 0;
        op_s.get_verzija();
        op_s.set_verzija(nwn);

        return true;
    }
    bool dowland_batch(){
        if(DowlandProgress < 91 && stanje == AZURIRA_SE){
               DowlandProgress += 10;
            return true;
        }
        return false;
    }
};
void ispis_os(const OSistem &os){
    cout<<"vrsta:";
    switch(os.get_vrsta()){
    case 1:
        cout<<"android"<<endl;
        break;
    case 2:
        cout<<"ios"<<endl;
        break;
    default:
        cout<<""<<endl;
        break;
    }
    cout<<"verzija:"<<os.get_vrsta()<<endl;
}
void ispisi_smartphone(const Smartphone &smart){
    cout<<"verzija os:"<<smart.get_verzija()<<endl;
    cout<<"vrsta:";
    switch(smart.get_vrsta()){
    case 1:
        cout<<"android"<<endl;
        break;
    case 2:
        cout<<"ios"<<endl;
        break;
    default:
        cout<<""<<endl;
        break;
    }
    cout<<"stanje smartphona:";
    switch(smart.get_stanje()){
    case 1:
        cout<<"ukljucen"<<endl;
        break;
    case 2:
        cout<<"iskljucen"<<endl;
        break;
    case 3:
        cout<<"standby"<<endl;
        break;
    case 4:
        cout<<"azurira se"<<endl;
        break;
    default:
        cout<<endl;
        break;
    }
}
int meni(){
    int i;
    cout<<"1.ukljuci"<<endl;
    cout<<"2.iskljuci"<<endl;
    cout<<"3.uspavaj"<<endl;
    cout<<"4.probudi"<<endl;
    cout<<"5.zavrsi update"<<endl;
    cout<<"6.stavi na zuriranje"<<endl;
    cout<<"7.povecaj progress"<<endl;
    cout<<"8.vidi smartphone"<<endl;
    cout<<"9.zavrsi sa opracijama"<<endl;
    cin>>i;
    return i;
}
int main()
{
    OSistem os;
    Smartphone smart;
    do{
        switch(meni()){
        case 1:
            if(smart.turnOn() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 2:
            if(smart.turn_of() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 3:
            if(smart.sleep() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 4:
            if(smart.wake_up() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 5:
            if(smart.finish_update() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 6:
            if(smart.start_update(2) == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 7:
            if(smart.dowland_batch() == true){
                cout<<"izvrseno"<<endl;
            }
            else{
                cout<<"nije izvrseno"<<endl;
            }
            break;
        case 8:
            ispisi_smartphone(smart);
            break;
        case 9:
            return 0;
        default:
            break;
        }
    }while(1);
    return 0;
}
