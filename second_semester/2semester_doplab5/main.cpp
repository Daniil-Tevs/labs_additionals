#include <iostream>

//template<typename T>
//class Products {
//public:
//    Products() {
//    }
//    ~Products() {  }
//protected:
//    T *menu = nullptr;
//};
//
//class Food : public Products<int> {
//public:
//    Food(int number){ menu = new int[number];}
//    virtual ~Food() {delete menu; }
//};
//class Bar : public Products<char>{
//public:
//    Bar(int number){ menu = new char[number];}
//    virtual ~Bar() {delete menu;}
//};
template < typename T>
class Basic{
    T *i;
public:
    Basic(int number)
    {
        i = new T[number];
    }
    ~Basic()
    {
        delete i;
    }
};

int main()
{
    auto* f= new Basic<int>(100);
    auto *b= reinterpret_cast<Basic<int> *>(new Basic<char>(200));
    delete f;
    *f=*b;
    delete b;
}


