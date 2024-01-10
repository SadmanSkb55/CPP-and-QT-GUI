#include <iostream>
#include <cstring>

using namespace std;

void reverseString(char* str) {
    if (str == nullptr) {
        return;
    }

    int length = strlen(str);
    char* start = str;
    char* end = str + length - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    const int maxSize = 100;
    char inputString[maxSize];

   
    cout << "Enter a string: "<<endl;
    cin.getline(inputString, maxSize);
    
     string savedstring=inputString;

    reverseString(inputString);

    cout << "Reversed string: " << inputString <<endl;
   
    if (savedstring==inputString)
    {
       cout<<"The original and reversed strings are the same."<<endl;
       cout<<" P A L I N D R O M I C"<<endl;
    }
    

    return 0;
}
