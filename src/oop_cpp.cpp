#include<iostream>

using namespace std;

template<class T>
class Relatable{
public:
    virtual T relate(T t1, T t2) = 0;
};

class Person{
public:
    string name;
    Person(string name){
        this->name = name;
    }

    class PersonRelation : public Relatable<Person>{
    public:
        Person relate(Person p1, Person p2){
            return Person("LovelyBaby");
        }
    };
};

template<typename T>
T execute(T& a, T& b, Relatable<T>* r){
    return r->relate(a, b);
}

int main(){
    Person p1 = Person("HandsomeBoy");
    Person p2 = Person("BeautifulGirl");
    Relatable<Person>* rp = new Person::PersonRelation;
    Person p3 = execute<Person>(p1, p2, rp);
    cout << p3.name << endl;

    return 0;
}

