#include <iostream>

using namespace std;

int main(){
    int i=42, j=31;
    double x = 3.14, y = 23.34;
    //auto p = 45ll; //add ll to try
    //cout << sizeof(p) <<endl;

    int & ref = i; //ref points to i variable
    
    cout << "i is: " << i << "; ref is: " << ref << endl;
    
    i=25;
    //if I assign something into i, also ref will change and vice versa
    cout << "i is: " << i << "; ref is: " << ref << endl;

    ref = 12;
    cout << "i is: " << i << "; ref is: " << ref << endl;

    return 0;
}