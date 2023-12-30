#include<iostream>
using namespace std;
int main() {
    int *pnum=NULL;
    pnum=new int;
    cout<<"Enter a number: ";
    cin>>*pnum;
    cout<<"\nYou entered : "<<*pnum<<" Adress: "<<pnum<<endl;
    delete pnum; //freeing the memory occupied by 'pnum'
     cout<<pnum<<endl;
    pnum=NULL;   //making NULL to avoid any accidental use of deleted memory.
    cout<<pnum<<endl;
    //If not made NULL, then it will point to some garbage value and may lead
    int *pint=NULL;
    int size;
    cout<<"How many elements do you want in array? ";
    cin>>size;
    pint = new int[size];  //dynamic allocation of memory for an array
    for(int i=0;i<size;i++) {
        cout<<"Element "<<i+1<<": ";
        cin>>pint[i];
        }
        cout<<"\nElements are:\n";
        for(int j=0;j<size;j++)
        cout<<pint[j]<<" ";
        delete[] pint;//deleting dynamically allocated memory for an array
        //use [] with delete to indicate that it is an array.
        

    
    return 0;


}