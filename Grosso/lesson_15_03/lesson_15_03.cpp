#include "Rc.h"
#include <iostream>

using namespace std;

//we can specify also the function in another file
int Rc::get_code(){
    return code; 
}

void Rc::set_code(int a){
    code = a;
}

int Rc2::get_code(Rc c){
    return c.code;
}

int get_code_extern(Rc c){

    return c.code;
}

Rc::Rc(){
    cout << code << " - class is instantiated!" << endl;

    arr_point = new char [200]; //allocate dinamically some resources
}

Rc::~Rc(){
    cout << code << "- object is destructed" << endl;
}

Rc::Rc(int n){
    code = n;
    cout << code << " - class is instantiated!" << endl;
}

int main(){
    int var(0);
    Rc r(15);
    cout << get_code_extern(r) << endl;

    Rc2 p;

    Rc q(99);
    cout << q.get_code() << endl;
    r.set_code(15);

    cout << r.get_code() << '\n';
    cout << p.get_code(r) << '\n';
    



    return 0;

}
