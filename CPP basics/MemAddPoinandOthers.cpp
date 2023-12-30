#include<iostream>
using namespace std;
void swap(string &name,string &name2);
int main() {
    string name;
    cout<<"Enter a name:"<<endl;
    cin>>name;
    cout<<"Memory Adress: "<<&name<<endl;
    string name2;
    cout<<"Enter another name:"<<endl;
    cin>>name2;
    cout<<"Memory Adress: "<<&name2<<endl;
    
    swap(name,name2);
    cout<<"After swapping names, the first name is : "<<name<<" And :"<<&name<<endl;
    cout<<"And the second name is : "<<name2<<" And :"<<&name2<<endl;

cout<<"Lets test pointer out"<<endl;
cout<<"Enter a String:"<<endl;
string strx;
cin>>strx;
string *str=&strx;//& is adress of operator and * is derefernce operator
cout<<*str<<endl;
cout<<"Address: "<<&strx<<endl;
string arr[]={"A","B","c"};
//string *parr=&arr; wrong
string *parr=arr; //just stores one variable
cout<<*parr<<endl;
//null pointer:
int *pointer=nullptr;
int x=1;
pointer=&x;
if(pointer==nullptr)
{
    cout<<"Null Pointer"<<endl;
    cout<<*pointer<<endl;
    }
    else{
    cout<<"Not Null Pointer"<<endl;
    cout<<*pointer<<endl;
    }

    return 0;
}
void swap(string &name,string &name2){
string temp;
    temp=name;
    name=name2;
    name2=temp;
}