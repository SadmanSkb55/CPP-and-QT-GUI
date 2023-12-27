#include<iostream>
using namespace std;
double add(double (&arr)[150], int range);
double subs(double (&arr)[150], int range);
double mul(double (&arr)[150], int range);
double div(double (&arr)[150], int range);
void runner();
unsigned long long factorial(int n);
void fiborunner();
int fibonacci(int n);
int main(){
cout<<"Add numbers(if u enter 0,it will be closed)(range 150)"<<endl;

double arr[150];
int count=0;
for (size_t i = 0; i < 150; i++)
{
     cout << "Enter number " << i+1 << ": ";
     double chk;
     cin >> chk;
    if (chk==0.0)
{
    break;
}else{
    arr[i]=chk;
count++;
}

}
cout<<"Which wan u want to do?1.Addition 2.substraction 3.Multiplication 4.Division"<<endl;
int f;
cin>>f;
switch (f)
{
case 1:
   cout<<add(arr,count);
    break;
    case 2:
   cout<<subs(arr,count);
    break;
    case 3:
  cout<< mul(arr,count);
    break;
    case 4:
  cout<< div(arr,count);
    break;
    default:
  cout<<"Invalid";
    break;
}
runner();
fiborunner();
return 0;
}
double add(double (&arr)[150],int range){
    double result=0.0;
for (size_t i = 0; i <range; i++)
{
    result+=arr[i];
}
return result;
}
double subs(double (&arr)[150],int range){
 double result=0.0;
for (size_t i = 0; i <range; i++)
{
    result-=arr[i];
}
return result;
}
double mul(double (&arr)[150],int range){
 double result=1.0;
for (size_t i = 0; i <range; i++)
{
    result*=arr[i];
}
return result;
}
double div(double (&arr)[150],int range){
 double result=0.0;
for (size_t i = 0; i <range; i++)
{
   if (arr[i] == 0) {
            cerr << "Error: Division by zero!" << endl;
            return 0.0;  
        }
        result /= arr[i];
}
return result;
}
void runner(){
int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Please enter a non-negative integer." <<endl;
    } else {
        cout << "Factorial of " << num << " is: " <<factorial(num)<<endl;
    }
}
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return static_cast<unsigned long long>(n)*factorial(n - 1);
}

void fiborunner(){
 int num;
    cout << "Enter a non-negative integer for Fibonacci: ";
    cin >> num;
    if (num < 0) {
        cout << "Please enter a non-negative integer." <<endl;
    } else {
        cout << "Fibonacci(" << num << ") is: " << fibonacci(num) <<endl;
    }

}
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}