#include <iostream>

using namespace std;

class Trougao{
protected:
    float a;
    float b;
    float c;
public:
    Trougao(){
        a = 2;
        b = 3;
        c = 4;
    }
    Trougao(float aa,float bb,float cc){
        a = aa;
        b = bb;
        c = cc;
    }
    Trougao(const Trougao &t){
        a = t.a;
        b = t.b;
        c = t.c;
    }
    float get_a()const{
        return a;
    }
    float get_b()const{
        return b;
    }
    float get_c()const{
        return c;
    }
    void set_a(const float aaa){
        a = aaa;
    }
    void set_b(const float bbb){
        b = bbb;
    }
    void set_c(const float ccc){
        c = ccc;
    }
    float get_obim(){
        return a + b + c;
    }
    float get_povrsina(){
        float d = (a + b +c)/2;
        float p = d * (d-a) * (d-b) * (d-c);
        return p;
    }

};
class JKTtrougao : public Trougao{
public:
    JKTtrougao() : Trougao(2,3,3){}
    JKTtrougao(float a,float b) : Trougao(a,b,b){}
    JKTtrougao(const JKTtrougao &jkt) : Trougao(jkt.a,jkt.b,jkt.c){}
};
class JSTtrougap : public JKTtrougao{
public:
    JSTtrougap() : JKTtrougao(3,2){}
    JSTtrougap(float a) : JKTtrougao(a,a){}
    JSTtrougap(const JSTtrougap &jst) : JKTtrougao(jst.a,jst.b){}
};
int main()
{
    Trougao t(2,3,4);
    JKTtrougao jkt(2,3);
    JSTtrougap jst(2);
    cout<<"povrsina trougla je:"<<t.get_povrsina()<<endl;
    cout<<"povrsina jednokokrakog trougla je:"<<jkt.get_povrsina()<<endl;
    cout<<"povrsina jednakostranicnog trougla je:"<<jst.get_povrsina()<<endl;

    return 0;
}
