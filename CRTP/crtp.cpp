#include <iostream>
#include <typeinfo>

template<typename T>
class Basic{

public:
    void p();
};

class Derive : public Basic<Derive>{

public:
    void implP();
};

template<>
void Basic<Derive>::p(){
    static_cast<Derive*>(this)->implP();
}

template<typename T>
void Basic<T>::p() {
    std::cout << "i'm Basic" << std::endl;
}


void Derive::implP(){
    std::cout << "i'm Derive" << std::endl;
}

int main(){
    Basic<Derive> b = Derive();
    b.p();
    auto c = Basic<int>();
    c.p();
}

