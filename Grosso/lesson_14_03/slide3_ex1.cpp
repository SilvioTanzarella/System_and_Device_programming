#include <iostream>

using namespace std; //with this command, we avoid using std::
//using std::cout -> with this command only cout can be used without std::

int main(int arcg, char ** argv){
    int v1,v2;
    //std::cout means cout (console out) is taken from the standard library
    //std::endl behaves like \n
    cout << "Hello World!" << endl;

    cout << "Enter two values: ";
    cin >> v1 >> v2;
    cout << "Sum: " << v1+v2 << endl;


    return 0;
}