#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class A {
public:
	string s;
	A() {
		cout << "Конструктор по умолчанию класса А" << endl;
	}

	A(const char* a) {
		s = a;
		cout << "Пользовательский Конструктор класса A" << endl;
		cout << s << endl;
	}

    A(const A& oth) {
        s = oth.s;
    }

	virtual ~A() {
		cout << "Деструктор класса A" << endl;
		cout << typeid(*this).name() << endl;
	}

    virtual A* copy() {
        return new A(*this);
    }
};

class B : public A {
public:
	B() {
		cout << "Конструктор  класса B" << endl;
	}
	B(const char* a) :A(a) {
		cout << "Пользовательский Конструктор класса B" << endl;
		cout << a << endl;
	}
    B(const B& obj) : A(obj) {};

	~B() {
		cout << "Деструктор класса B" << endl;
		cout << typeid(*this).name() << endl;
	}
    B* copy() override {
        return new B(*this);
    }
};

template<class T>
void del(const T& v) {
    for (auto& i : v)
        delete i;
}


vector<A*>v;
list <A*> l;

int main() {
	setlocale(LC_ALL, "Russian");

	l.push_back(new A("first"));
	l.push_back(new B("second"));
	// скопировать из списка в вектор
    for (A* elm : l) {
        v.push_back(elm->copy());
        };

	del(v);
    for (A* elm : l) {
        delete elm;
    }

	return 0;
}