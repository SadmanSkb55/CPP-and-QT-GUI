#include<iostream>
#include <typeinfo> 
#include <string>  

template<typename T,typename U>



// T max(T x,U y){
//     return (x > y)? x : y;
// }
auto max(T x,U y){
    return (x > y)? x : y;
}
struct stx
{
    std::string name;
    int age;
    float id;
   unsigned long long phonenumber;
   bool con;
};
void printinfo(stx s);
void printinfo(stx s, std::string color);
using namespace std;
enum code {A=0,B=1,C=3,D=4,E=5,F=6};
int main() {
cout<<"Enter A number"<<endl;
int x;
cin>>x;
cout<<"Enter Another Number"<<endl;
double y;
cin>>y;
cout<<max(x,y)<<endl;
cout<<typeid(decltype(x)).name()<<endl; //Returns i for integer
cout<<typeid(decltype(y)).name()<<endl;  // Returns d for double

stx s1 = {"John",23,45.678901234,1234567898765,true};
cout<<"Name: "<<s1.name<<endl;
cout<<"Age: "<<s1.age<<endl;
cout<<"ID: "<<s1.id<<endl;
cout<<"PhoneNumber: "<<s1.phonenumber<<endl;
cout<<"IsConnected? "<<(s1.con?"Yes":"No")<<endl;

//cout<<s1.name<<s1.age<<s1.con<<s1.id<<s1.phonenumber<<endl;

stx s2;

cout<<"Enter name"<<endl;
cin>>s2.name;
cout<<"Enter Age"<<endl;
cin>>s2.age;
cout<<"Enter ID"<<endl;
cin>>s2.id;
cout<<"Enter PhoneNumber"<<endl;
cin>>s2.phonenumber;
cout<<"Is he connected? Y/N "<<endl;
char c;
cin>>c;
if(c=='Y'||c=='y')
s2.con= true;
else
s2.con = false;
// cout<<"The Details are as Follows:"<<endl;
// cout<<"Name: "<<s2.name<<endl;
// cout<<"Age: "<<s2.age<<endl;
// cout<<"ID: "<<s2.id<<endl;
// cout<<"Phone Number: "<<s2.phonenumber<<endl;
// if(s2.con == true)
// cout<<"He is Connected."<<endl;
// else
// cout<<"He is not Connected."<<endl;
printinfo(s2);
printinfo(s2,std::string("Black"));


int input;
cout<<"Enter a character within A to F"<<endl;
cin>>input;
code cd = static_cast<code>(input);
// int num = hexToDec(c);
// cout<<num<<endl;
switch (cd)
{
case A: 
cout<<"You Entered A";
    break;
    case B: 
cout<<"You Entered B";
    break;
    
    case C: 
cout<<"You Entered C";
    break;
    case D: 
cout<<"You Entered D";
    break;
    case E: 
cout<<"You Entered E";
    break;
    case F: 
cout<<"You Entered F";
    break;

default:
cout<<"wrong input"<<endl;
    break;
}
return 0;

}
void printinfo(stx s) {
    cout<<"\nName : " << s.name << endl;
    cout << "Age : " << s.age << endl;
    cout << "Id : " << s.id << endl;
    cout << "Phone number : " << s.phonenumber << endl;
    if (s.con) {
        cout << "User is connected.\n";
        } else {
            cout << "User is not connected.\n";
        }
}
void printinfo(stx s,std::string color){
    cout<<"\nName : " << s.name << endl;
    cout << "Age : " << s.age << endl;
    cout << "Id : " << s.id << endl;
    cout << "Phone number : " << s.phonenumber << endl;
    if (s.con) {
        cout << "User is connected.\n";
        } else {
            cout << "User is not connected.\n";
}
cout<<"Skin color: "<<color<<endl;
}