#include<iostream>
using namespace std;
int main() {
    int a,b;
    cout << "Enter the value of 'a': ";
    cin>>a;
    cout<<"Enter the value of 'b': ";
    cin>>b;
    if(a==b){
        cout<<"\nBoth numbers are equal.";
        cout<<"Here multiplication and addition same :"<<a*b<<" and "<<a+b<<endl;
        cout<<"Here Division is 1 and substraction is 0 :"<< a/b << " and "<<a-b<<endl;
        cout<<"Reminder :"<<a%b<<endl;

    }
    else{
        int sum=a+b;
        int mul=a*b;
        int rem=a%b;
        int subst;
        double div;
        if(a>b){
             subst=a-b;
             div=(double)a/b;
        }
        else{
             subst=b-a;
             div=static_cast<double>(b)/a;
        }
        cout<<"Sum: "<<sum<<"\nmul: "<<mul<<"\nrem: "<<rem<<"\nsubs: "<<subst<<"\ndiv: "<<div<<endl;
    }
double ax=a;//typecasted    
a+=2;
b-=2;
ax*=b;
double*bx=reinterpret_cast<double*>(b);//reinterpret_cast is a powerful casting operator that can convert any pointer type
const double ax2=ax;
double* axc = const_cast<double*>(&ax2);//constant type cast
cout<<"Value after adding 2 to 'a' and subtracting 2 from 'b'\n";
cout<<"New Value of 'a' is : "<<a<<"\nNew Value of 'b' is : "<<b<<"\
\nMultiplication of old values of 'a' & 'b' : "<<axc<<endl;
cout<<bx;
cout<<ax2;
cout<<ax;
cout<<axc;

bool isEqual = (a == ax);    
bool isNotEqual = (b != a);  
bool isLess = (b < a);       
bool isGreater = (ax2 > a);    
bool isLessOrEqual = (ax <= ax2);  
bool isGreaterOrEqual = (bx >= bx);  

bool condition1 = true, condition2 = false;
bool resultAND = condition1 && condition2;  
bool resultOR = condition1 || condition2;   
bool resultNOT = !condition1; 

int bitwiseAND = a & b;  
int bitwiseOR = a | b;   
int bitwiseXOR = a ^ b;  
int bitwiseNOT = ~a;    
int leftShift = a << 1;  
int rightShift = a >> 1; 

//cout<<"\n"<<bitwiseAND<<"\n"<<bitwiseOR<<"\n"<<bitwiseXOR<<"\n"<<bitwiseNOT<<"\n"<<leftShift<<"\n"<<rightShift<<endl;
cout << "\nIs Equal? " << isEqual ;         // Output: 1
cout << "\nIs Not Equal? " << isNotEqual ;   // Output: 0
cout << "\nIs Less Than? " << isLess ;      // Output: 0
cout << "\nIs Greater Than? " << isGreater ; // Output: 1
cout << "\nIs Less than or equal to? " << isLessOrEqual ;       // Output: 1
cout << "\nIs greater than or equal to? " << isGreaterOrEqual ;  // Output: 0
cout << "\nAND operator : " << resultAND ;          // Output: 0
cout << "\nOR operator : " << resultOR ;           // Output: 1
cout << "\nNOT operator : " << resultNOT ;         // Output: 0
cout << "\nBitwise AND : " << bitwiseAND ;       // Output: 0
cout << "\nBitwise OR : " << bitwiseOR ;        // Output: 3
cout << "\nBitwise XOR : " << bitwiseXOR ;      // Output: 1
cout << "\nBitwise NOT : " << bitwiseNOT ;      // Output: -3
cout << "\nLeft Shift : " << leftShift ;         // Output: 4
cout << "\nRight Shift : " << rightShift ;       // Output: 1</s>

int day;

cout<<"\nEnter a day int";
cin>>day;
switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        default:
            std::cout << "Unknown day" << std::endl;
    }

    if (a > 10) {
        std::cout << "a is greater than 10." << std::endl;
    } else if (b > 5) {
        std::cout << "x is greater than 5 but not greater than 10." << std::endl;
    } else {
        std::cout << "a,b is not greater than 10 or 5." << std::endl;
    }

}