#include<iostream>
#include<functional>

using namespace std;

class Person{
public:
    string name;
    Person(string name){
        this->name = name;
    }

    static Person love(Person p1, Person p2){
        return Person("LovelyBaby");
    }
};

template<typename T>
T execute(T& a, T& b, function<T(T, T)> func){
    return func(a, b);
}

int main(){
    Person p1 = Person("HandsomeBoy");
    Person p2 = Person("BeautifulGirl");
    Person p3 = execute<Person>(p1, p2, Person::love);
    Person p4 = execute<Person>(p1, p2, [](Person x, Person y) -> Person{Person p = Person::love(x,y);return p;});
    auto func = [](Person x, Person y) -> Person{Person p = Person::love(x,y);return p;};
    Person p5 = func(p1, p2);
    cout << p3.name << endl;
    cout << p4.name << endl;
    cout << p5.name << endl;

    return 0;
}

