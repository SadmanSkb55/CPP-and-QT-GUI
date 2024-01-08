#include <iostream>
using namespace std;

int main() {  
    int* ptr = new int;
    cout<<"Enter an INt"<<endl;
    int x;
    cin>> x; 
    *ptr=x; 
    auto** ptrToPtr = &ptr;
    cout<<"Value just by variable: "<<x<<endl;
    cout<<"Adress of variable that stored number: "<<&x<<" And the adress of primary pointer "<<&ptr<<endl;
    cout <<"Value through pointer to pointer: "<<**ptrToPtr <<" adress "<<&ptrToPtr<<endl;
    delete ptr;
    cout<<"After Deleting: "<<endl;
    cout<<"Value just by variable: "<<x<<endl;
    cout<<"Adress of variable that stored number: "<<&x<<" And the adress of primary pointer "<<&ptr<<endl;
    cout <<"Value through pointer to pointer: "<<**ptrToPtr <<" adress "<<&ptrToPtr<<endl;
    return 0;
}
