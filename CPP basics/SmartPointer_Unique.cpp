#include <iostream>
#include <memory>
using namespace std;

void uniquePtrExample(int newval) {
   unique_ptr<int> ptr(new int(42));
    cout << "Value: " << *ptr <<endl;
    *ptr = newval;
     cout << "Modified Value: " << *ptr <<endl;
   
} 
int main() {
    uniquePtrExample(1000); 
    return 0; 
}
