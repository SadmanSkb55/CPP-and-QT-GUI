#include <iostream>
#include <memory>
using namespace std;
void sharedPtrExample(int newval,int newval2) {
    shared_ptr<int> ptr(new int(100));
    shared_ptr<int> ptr2 = ptr;
    *ptr += newval;
    *ptr2 += newval2;
    cout << "Value: " << *ptr <<endl;
    cout << "Value: " << *ptr2 <<endl;
}

int main() {
    sharedPtrExample(10,20);
    return 0;
}
