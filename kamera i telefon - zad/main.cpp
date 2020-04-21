#include <iostream>

using namespace std;

class Kamera{
    protected:
        int megaPiksel;
        int freeSpace;
        static int photoCounter;
    public:
        Kamera(){
            megaPiksel = 108;
            freeSpace = 16000;
            photoCounter = 10;
        }
        Kamera(int mp,int fp,int pc){
            megaPiksel = mp;
            freeSpace = fp;
            photoCounter = pc;
        }
        Kamera(const Kamera &kopija){
            megaPiksel = kopija.megaPiksel;
            freeSpace = kopija.freeSpace;
            photoCounter = kopija.photoCounter;
        }
        int get_counter()const{
            return photoCounter;
        }
        bool slikaj(){
            freeSpace -= megaPiksel;
            if(freeSpace >= 0){
                return true;
            }
            return false;
        }

};
class VideoKamera : public Kamera{
private:
    static int videoCounter;
public:
    VideoKamera(){
        megaPiksel = 216;
        freeSpace = 32000;
        photoCounter = 10;
        videoCounter = 10;
    }
    VideoKamera(int vc,int a,int b,int c){
        megaPiksel = a;
        freeSpace = b;
        photoCounter = c;
        videoCounter = vc;
    }
    int get_vc()const{
        return videoCounter;
    }
    bool snimaj(int sec){
        freeSpace -= (megaPiksel * sec);
        if(freeSpace >= 0){
            return true;
        }
        return false;
    }
};
class Telefon{
protected:
    string broj;
public:
    Telefon(){
        broj = "0613150983";
    }
    Telefon(string br){
        broj = br;
    }
    bool pozovi(string br1){
        if(broj == br1){
            return false;
        }
        return true;
    }

};
class TelefonGen2 : public Telefon{
protected:
    Kamera k;
public:
    TelefonGen2() : k(64,16000,5) {
        broj = "0613150983";
    }
    TelefonGen2(int a,int b,int c,string bro) : k(64,16000,5) {
        broj = bro;
    }
    bool slikajSliku(){
        return k.slikaj();
    }

};
class TelefonGen3 : public Telefon{
protected:
    VideoKamera vk;
public:
    TelefonGen3() : vk(108,16000,8,8){
        broj = "0613150983";
    }
    TelefonGen3(int a,int b,int c,int vc,string br) : vk(108,16000,8,8){
        broj = br;
    }
    bool snimiVideo(int secc){
        return vk.snimaj(5);
    }
};
int main()
{


    return 0;
}
