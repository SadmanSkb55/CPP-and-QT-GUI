#include <iostream>
using namespace std;

class ptrv{
    public:
void doubleValue(double* ptr) {
    if (ptr != nullptr) {
        *ptr *= 2;
    }
}
void doubleValue(double* ptr,double num) {
    if (ptr != nullptr) {
     //*ptr = static_cast<int>(static_cast<double>(*ptr) * num);
     *ptr = double(*ptr)*num;
    }
}
};

int main() {
    double num;
    cout << "Enter an number: ";
    cin >> num;
     cout << "Original value: " <<num<<" Adress "<<&num<<endl;  
     ptrv px;
    cout<<"Which one you want? 1.Just double 2.Multiply the value with type Double"<<endl; 
    int inp;
    cin>>inp;
    switch (inp)
    {
    case 1:
    px.doubleValue(&num);
        break;
    case 2:
    cout<<"Enter a value to multiply with"<<endl;
    double dbl;
    cin>>dbl;
    px.doubleValue(&num,dbl);
        break;
    default:
    cout<<"Invalid"<<endl;
        break;
    }
    cout << "Doubled value: " <<" Adress "<<&num<<endl;  
    cout<<"Same Adress"<<endl;
    return 0;
}
