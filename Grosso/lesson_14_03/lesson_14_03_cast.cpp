#include <iostream>

using namespace std;

int sum(int a, int b){
    return a + b;
}

double sum(double a, double b){
    return a + b;
}

int f(){
    return 42;
}

int main(){

    int a=42, y;
    double b = 3.14, x, z;
    
    //x = sum(a,b); I get an error
    y = sum(a, (static_cast<int>(b)));
    z = sum((static_cast<double>(a)),b);
    cout << "y= " << y << endl << "z = " << z << endl;

    int i = 42;
    void* vp = &i;
    int* ip = static_cast<int*>(vp);
    cout << "ip = " << ip << endl << "vp = " << vp << endl;

    return 0;
}