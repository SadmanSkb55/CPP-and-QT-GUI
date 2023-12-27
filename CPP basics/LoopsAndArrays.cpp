#include<iostream>
#include <cmath>
#include <array>



using namespace std;
int main(){
    int c;
    double v=0.0;
int count=0;
for(int i=0;i<=6;i++){
    cout<<"Running: "<<i<<endl;
    count+=i;
}
cout<<"Counted: "<<count<<endl;
while (c!=10)
{
    if(c%2==0){
         cout<<"****"<<endl;
    }else
     cout<<"*******"<<endl;
  c++;
}

do{
if(fabs(v - 10.0) < 1e-10){
         cout<<"++"<<endl;
    }else
     cout<<"+++"<<endl;
  v+=0.10;
}while(v!=.20);

 for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            break; 
        }
        if (i % 2 == 0) {
            continue; 
        }
        cout << i << " ";
    }

cout << endl;
int x;
cout<<"Enter the size of array"<<endl;
cin>>x;
string arrayx[x];
for (int i = 0; i < x; i++)
{
   cout<<"Enter "<<i+1<<"th name"<<endl;
   cin>>arrayx[i];
}
for (size_t i = 0; i < x; i++)
{
 cout<<i+1<<"th: "<<arrayx[i]<<endl;
}

cout<<"Enter A Matrix"<<endl;
int row,column;
cout<<"Enter number of rows:"<<endl;
cin>>row;
cout<<"Enter number of columns:"<<endl;
cin>>column;
int matrix[row][column];
for (size_t i = 0; i < row; i++)
{
    for (size_t j = 0; j < column; j++)
    {
       cout<<"Value of :"<<i<<"x"<<j<<endl;
       cin>>matrix[i][j];
    }   
}
cout<<"Inserted matrix: "<<endl;
for (size_t i = 0; i < row; i++)
{
    for (size_t j = 0; j < column; j++)
    {
       cout<<"["<<matrix[i][j]<<"]";
    }  
    cout<<endl; 
}
cout<<"Enter Another Matrix"<<endl;
int row2,column2;
cout<<"Enter number of rows:"<<endl;
cin>>row2;
cout<<"Enter number of columns:"<<endl;
cin>>column2;
int matrix2[row2][column2];
for (size_t i = 0; i < row2; i++)
{
    for (size_t j = 0; j < column2; j++)
    {
       cout<<"Value of :"<<i<<"x"<<j<<endl;
       cin>>matrix2[i][j];
    }   
}
cout<<"Inserted 2nd matrix: "<<endl;
for (size_t i = 0; i < row2; i++)
{
    for (size_t j = 0; j < column2; j++)
    {
       cout<<"["<<matrix2[i][j]<<"]";
    }  
    cout<<endl; 
}
int o;
cout<<"Please Select which u want to do:1.Addition 2.Multiplication 3.Transpose 4.Inverse"<<endl;
switch (o)
{
    case 1:
   cout<<"will be cooked at function"<<endl;
    break;
    case 2:
    cout<<"will be cooked at function"<<endl;
    break;
     case 3:
    cout<<"will be cooked at function"<<endl;
    break;
     case 4:
    cout<<"will be cooked at function"<<endl;
    break;

default:
    break;
}
// int F;
// cout<<"Enter the size of stlArray:"
// cin>>F;
array<int,10> stlArray={};//standard library array
for (size_t i = 0; i < stlArray.size(); i++)
{
   cout<<"Value of STL array :"<<i<<endl;
   cin>>stlArray[i];
}
cout<<"Size of STL array: "<<stlArray.size()<<endl;
for (const auto& element : stlArray) {
    cout << element << " ";
}
cout <<endl;


return 0;
}