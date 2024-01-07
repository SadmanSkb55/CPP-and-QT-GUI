#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements: "<<endl;
    cin >> size;
    int arr[size];  
    for (int i = 0; i < size; i++) {
        cout << "Element [" << i+1 << "]: ";
        cin >> arr[i] ;
        }
    int* ptrArr[size];

    for (int i = 0; i < 5; ++i) {
        ptrArr[i] = &arr[i];
    }
    int size2;
    cout << "\nEnter the index number of which element u want to see "<<endl;
    cin >> size2;
    cout <<"The  element : "<<*(ptrArr[size2])<<endl;
    cout<<"The adress of pointer in pointer array "<<&(ptrArr[size2])<<" the adress of element "<<&arr[size2]<<endl;
    cout<<"They are not the same xd"<<endl;

    return 0;
}
