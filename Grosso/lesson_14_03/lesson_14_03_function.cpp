#include <iostream>

using namespace std; 

void f(int j){
    j=27; //it doesn't change the value of i
}

void f_pointer(int *p){ //p stores the copy of the address of i
    if(p != nullptr)
        *p = 27; //it changes the value of i
}

void f_reference(int &r){
    r = 10; //it changes the value of i
}

int main(){
    int i=10;
    
    f(i);
    cout << "i: " << i << endl;

    f_pointer(&i); //passage by address
    cout << "i: " << i << endl;
    
    f_reference(i); //passage by reference
    cout << "i: " << i << endl;


    return 0;
}