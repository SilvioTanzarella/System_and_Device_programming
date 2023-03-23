#include <iostream>
#include <vector>

using namespace std; 

int main(void){
    
    vector<int> vet{0,1,2,3,4,5,6,7,8,9};

    for(vector<int>::iterator it=vet.begin(); it != vet.end(); ++it)
        cout << *it << "";
    cout << endl;

    for(auto &it : vet) //with a reference we modify the content of the vector
        cout << ++it << "";
    cout << endl;

    for(auto it : vet)
        cout << it << "";
    cout << endl;

    return 0;
}