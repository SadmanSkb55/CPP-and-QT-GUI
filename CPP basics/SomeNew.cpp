#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

typedef std::vector<std::pair<std::string,int>>pairlist_t;
typedef std::string text_t;
typedef int num_t;
using char_t=std::string;
using num_2=float;

namespace first{
    int x=9;
}
namespace second{
    int x=8;
}

void adder();
void adder(int n1,int n2);
void adder(int n1,int n2,double n3);

int main(){
int x=7;
cout<<first::x<<endl;
cout<<second::x<<endl;
cout<<x<<endl;
first::x=second::x+x;
cout<<"After change "<<first::x<<endl;


pairlist_t pairlist;
text_t txt="Hello";
num_t num=8;
num_2 num2=8.8;
char_t character="c";

cout<<txt<<"\n"<<num<<"\n"<<num2<<"\n"<<character<<endl;
double z=max(first::x,second::x);
double z2=min(static_cast<num_2>(num),num2);
cout<<"max: "<<z<<endl;
cout<<"min: "<<z2<<endl;
double f=2.58;
double y=7.77;
cout<<floor(f)<<endl;
cout<<ceil(y)<<endl;
cout<<pow(f,y)<<endl;
cout<<sqrt(y)<<endl;
cout<<abs(f-y)<<endl;

int g;
cout<<"enter any integer"<<endl;
cin>>g;
g>=0?cout<<"Positive"<<endl:cout<<"negative"<<endl;//ternary
string name;
cout<<"enter your name"<<endl;
cin.ignore();
getline(cin,name);
cout<<"Length of name: "<<name.length()<<endl;
name.empty()?cout<<"enter your name"<<endl:cout<<"welcome "<<name<<endl;
name.append("@gmail.com");

cout<<name<<endl;
cin.ignore();
cout<<name.at(name.length())<<endl;
name.insert(name.length()-1,"u");
cout<<name<<endl;
name.erase(name.length()-3,1);
cout<<"do you want to find any character?"<<endl;
string fin;
cin>>fin;
name.find(fin)?cout<<"Found":cout<<"not found"<<endl;
name.clear();
cout<<"Name cleared: "<<name<<endl;

//random genarator
srand(time(NULL));
int num3=rand();
cout<<"Random number: "<<num3<<endl;

int a=1;
int b=2;
double c=4.4;


adder();
adder(a,b);
adder(a,b,c);

return 0;

}
void adder(){
    cout<<"0"<<endl;
}
void adder(int n1,int n2){
    cout<<n1+n2<<endl;
}
void adder(int n1,int n2,double n3){
    cout<<n1+n2+(int)n3<<endl;
}