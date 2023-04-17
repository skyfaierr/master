
#include <iostream>
#include <vector>

class Class1 {
private:
    const float* num1;
public:
    int m = 9;
    Class1() : num1(new float(9.99)) {}
    virtual ~Class1() { delete num1; }
    virtual Class1* copy() { return new Class1(*this); };
};

class Class2: public Class1 {
private:
    const int* num2;
public:
    Class2() :num2(new int(999)) {}
    virtual ~Class2() { delete num2; };
    virtual Class2* copy() { return new Class2(*this); };
};

void my_copy(std::vector<Class1*>& vect, Class1& obj) {
    Class1* copy_obj = obj.copy();
    vect.push_back(copy_obj);
}

int main()
{
    std::vector<Class1*> vector;
    Class1 obj1;
    Class2 obj2;
    Class1 obj3;
    Class1 obj4;
    Class2 obj5;

    my_copy(vector, obj1);
    my_copy(vector, obj2);
    my_copy(vector, obj3);
    my_copy(vector, obj4);
    my_copy(vector, obj5);

    for (int i = 0; i < vector.size(); ++i) {
        if (typeid(*vector[i]) == typeid(Class1)) { std::cout << i + 1 << " object class is Class1. \n"; }
        if (typeid(*vector[i]) == typeid(Class2)) { std::cout << i + 1 << " object class is Class2. \n"; }
    }

    return 0;
}
