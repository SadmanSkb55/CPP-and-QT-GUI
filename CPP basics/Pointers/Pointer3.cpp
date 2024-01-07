#include <iostream>
using namespace std;
int main() {
    
    int* dynamicInt = new int;
    cout<<"Enter an Integer: "<<endl;
    cin>> *dynamicInt;
    cout << "Value of the dynamically allocated integer: " << *dynamicInt<<endl;
    cout<<"The adress of dynamic memory : "<<&dynamicInt<<endl;
    delete dynamicInt;
    cout << "Value of the dynamically allocated integer after deleting the dynamic memory: " << *dynamicInt<<endl;
    cout<<"The adress of dynamic memory now : "<<&dynamicInt<<endl;
    cout<<"Same address everybody"<<endl;
    
    return 0;
}
