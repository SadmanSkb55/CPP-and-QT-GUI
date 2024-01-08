#include <iostream>
using namespace std;

int sumArr(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += *(arr + i); 
    }
    return sum;
}

int main() {
    //dynamic one
    int size;
    cout <<"Enter the size of the array(Dynamic): "<<endl;
    cin >> size;
    int* Arr=new int[size];
    cout <<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >>Arr[i];
    }
    int* ptrArr[size];
    for (int i = 0; i < size; ++i) {
        ptrArr[i] = &Arr[i];
    }
    cout << "\nElements in Array are using pointer: \n";
    for (int j = 0; j < size; ++j) {
        cout << *ptrArr[j] <<" And Adress"<<&ptrArr[j]<< endl;
        }
    int result = sumArr(Arr,size);
    cout <<"Sum of array elements: "<<result<<endl;

    delete[] Arr;
    cout << "\nElements in Array are after delating dynamic array: \n";
    for (int j = 0; j < size; ++j) {
        cout <<Arr[j] <<" And Adress"<<&Arr[j]<< endl;
        }
    int resultx = sumArr(Arr,size);
    cout <<"Sum of array elements: "<<resultx<<endl;

    int sizef;
    cout << "Enter the size of the array(NOT DYNAMIC): ";
    cin >> sizef;
    int Arr2[sizef];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < sizef; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >>Arr2[i];
    }
    int* ptrArr2[sizef];
    for (int i = 0; i < sizef; ++i) {
        ptrArr2[i] = &Arr2[i];
    }
    cout << "\nElements in Array are using pointer: \n";
    for (int j = 0; j < sizef; ++j) {
        cout << *ptrArr2[j] <<" And Adress"<<&ptrArr2[j]<< endl;
        }
    int resultf = sumArr(Arr2,sizef);

    cout << "Sum of array elements: " << resultf<< endl;

    return 0;
}
