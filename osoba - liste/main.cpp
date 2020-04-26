#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;



using namespace std;

template <class T>
class List{
	private:
		struct listEl{
			T content;
			struct listEl* next;
		};
		listEl *head;
		listEl *tail;
		int noEl;

	public:
		List(){
			head=tail=NULL;
			noEl=0;
		}

		List(const List<T>&);

		List<T>& operator=(const List<T>&);

		virtual ~List();

		int size() const { return noEl; }

		bool empty() const { return head == NULL ? 1 : 0; }

		bool add(int n, const T& newContent) {
	if(n < 1 || n > noEl + 1)
		return false;
	else {
		listEl* newEl = new listEl;
		if(newEl == NULL)
			return false;
		else {
			newEl->content = newContent;
			if(n == 1) {
				newEl->next = head;
				head = newEl;
			} else if(n == noEl + 1) {
				newEl->next = NULL;
				tail->next = newEl;
			} else {
				listEl* temp = head;
				for(int i = 2; i < n; i++)
					temp = temp->next;
				newEl->next = temp->next;
				temp->next = newEl;
			}
			noEl++;
			if(newEl->next == NULL)
				tail = newEl;
			return true;
		}
	}
}

		bool remove(int);

		bool read(int, T&)const;

		void clear();
};


template <class T>
ostream& operator<<(ostream& out, const List<T>& rl) {
	out << endl;
	out << "--------" << endl;
	for(int i = 1; i <= rl.size(); i++){
		if(i != 1) out << ", ";
		T res;
		rl.read(i, res);
		out << res;
	}
	out << endl << "--------" << endl;
	return out;
}

template <class T>
List<T>::List(const List<T>& rl) {
	head = NULL;
	tail = NULL;
	noEl = 0;

	for(int i = 1; i <= rl.noEl; i++){
		T res;
		if(rl.read(i, res))
			add(i, res);
	}
}

template <class T>
List<T>& List<T>::operator=(const List<T>& rl) {
	if(this != &rl) {
		clear();
		head = NULL;
		tail = NULL;
		noEl = 0;

		for(int i = 1; i <= rl.noEl; i++){
			T res;
			if(rl.read(i, res))
				add(i, res);
		}
	}
	return *this;
}

template <class T>
List<T>::~List() {
	while(!empty())
		remove(1);
}



template <class T>
bool List<T>::remove(int n){
	if(n < 1 || n > noEl)
		return false;
	else {
		if(n == 1) {
			listEl* del = head;
			head = head->next;
			if(tail == del)
				tail = NULL;
			delete del;
			noEl--;
		} else {
			listEl* temp = head;
			for(int i = 2; i < n; i++)
				temp = temp->next;
			listEl* del = temp->next;
			temp->next = del->next;
			if(tail == del)
				tail = temp;
			delete del;
			noEl--;
		}
		return true;
	}
}

template <class T>
bool List<T>::read(int n,T& retVal) const {
	if(n < 1 || n > noEl)
		return false;
	else {
		if(n == 1)
			retVal = head->content;
		else if(n == noEl)
			retVal = tail->content;
		else {
			listEl* temp = head;
			for(int i = 1; i < n; i++)
				temp = temp->next;
			retVal = temp->content;
		}
		return true;
	}
}

template <class T>
void List<T>::clear() {
	while(!empty())
		remove(1);
}
class Osoba{
protected:
    string ime,prezime;
public:
    Osoba(){
        ime = "milos";
        prezime = "mrdja";
    }
    Osoba(string imee,string pre){
        ime = imee;
        prezime = pre;
    }
    Osoba(const Osoba &kopija){
        ime = kopija.ime;
        prezime = kopija.prezime;
    }
    virtual void ispis(){
        cout<<"ime:"<<ime<<"\nprezime:"<<prezime<<endl;
    }
};
class Student : public Osoba{
protected:
    int brIndeksa;
public:
    Student() : Osoba("milos","mrdja") {
        brIndeksa = 123;
    }
    Student(string imee,string pre,int br) : Osoba(imee,pre){
        brIndeksa = br;
    }
    Student(const Student &kopija) : Osoba(kopija.ime,kopija.prezime){
        brIndeksa = kopija.brIndeksa;
    }
    void ispis(){
        Osoba::ispis();
        cout<<"br. indeksa:"<<brIndeksa<<endl;
    }
};
class Profa : public Student{
protected:
    string predmet;
public:
    Profa() : Student("milos","mrdja",123){
        predmet = "mata";
    }
    Profa(string imee,string pre,string pred,int br) : Student(imee,pre,br){
        predmet = pred;
    }
    Profa(const Profa &kopija) : Student(kopija.ime, kopija.prezime, kopija.brIndeksa){
        predmet = kopija.predmet;
    }
    void ispis(){
        Student::ispis();
        cout<<"predmet:"<<predmet<<endl;
    }
};
class Ucionica{
protected:
    List <Osoba> osobe;
    string naziv;
    int brMesta;
public:
    Ucionica(){
        naziv = "ucionica";
        brMesta = 30;
    }
    Ucionica(string a,int br){
        naziv = a;
        brMesta = br;
    }
    Ucionica(const Ucionica &kopija){
        naziv = kopija.naziv;
        brMesta = kopija.brMesta;
    }
    bool dodajOsobu(const Osoba &o){
        if(osobe.size() < brMesta){
            return osobe.add(osobe.size() + 1, o);
        }
        return false;
    }
    void ispis() const{
        if(osobe.size() == 0){
            cout<<"ucionica je prazna"<<endl;
        }
        else{
            Osoba os;
            cout<<"u ucionici su:"<<endl;
            for(int i = 1;i < osobe.size();i++){
                osobe.read(i,os);
                os.ispis();
            }
        }
    }
};

int main()
{   List<Osoba> oso;
    Osoba o;
    Student st;
    Profa p;
    cout<<"podaci osobe:"<<endl;
    o.ispis();
    cout<<"\npodaci studenta:"<<endl;
    st.ispis();
    cout<<"\npodaci profesora:"<<endl;
    p.ispis();
    Ucionica u;
    u.dodajOsobu(o);
    Ucionica uu;
    for(int i = 1; i < oso.size();i++){
        oso.read(i,oso);
        cout<<"na poziciji "<<i<<"jeste:"<<oso<<endl;
    }

    return 0;
}
