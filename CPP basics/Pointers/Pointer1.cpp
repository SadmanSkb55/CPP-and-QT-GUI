#include <iostream>
using namespace std;

int main() {
    int num1,num2;
    int*ptr1 = &num1;
    num1= 100;
    cout << "The value of number 1 using the pointer: " <<*ptr1<<endl;
    cout<<"The adress of pointer "<<&ptr1<<" the adress of number 1 "<<&num1<<endl;
    cout<<"They are not the same xd"<<endl;
    return 0;
}
