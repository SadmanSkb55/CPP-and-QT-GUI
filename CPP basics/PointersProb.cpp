//understanding the pointer
//pointer is a variable that holds memory address of another variable. It allows us to access the value
#include<iostream>
using namespace std;

void swapNumbers(int* magicBox1, int* magicBox2) {
    int temp = *magicBox1;
    *magicBox1 = *magicBox2;
    *magicBox2 = temp;
}


int main(){
   string myHousename="Alabama";
   string* myAdress=&myHousename;
   cout<<"The house name is "<<*myAdress<<" which is situated at adress: "<<myAdress<<endl; 
    string myfrenshouse="Miami";
    string* myfrenshouseaddress=&myfrenshouse;
    cout<<"My friend's house name is "<<myfrenshouse<<" which is situated at adress: "<<&myfrenshouse<<endl; 
//then why do we use pointers?
//1)to store addresses in other variables so that we can manipulate them later on, like if
//we want to change the housename then we just need to point our pointer to new address and
//change it there instead of searching for this variable every time again and again.
cout<<"I will now give you the address of my friends house."<<endl;
cout<<"Please give me the address:"<<endl;
string* yourAddress=new string();
cin>>*yourAddress;
cout<<"Now I will go to my house by using the address given by you."<<endl
<<"So the house name should be : "<<*yourAddress<<endl;

 // Your magic box can hold a secret number.
    int* dynamicNumber = new int;

    // You can put your secret number in the magic box.
    *dynamicNumber = 123;

    // You can check your secret number whenever you want.
    cout << "Your secret number is: " << *dynamicNumber << endl;

    // Don't forget to return the magic box when you're done.
    delete dynamicNumber;

    int toyCars[] = {1, 2, 3, 4, 5};  // Your row of toy cars.

    // Your friend (the pointer) points to the first car.
    int* pointerToCars = toyCars;

    // Your friend can tell you about the first car.
    cout << "The first toy car is: " << *pointerToCars << endl;

int x = 5, y = 10;  // Your two magic numbers.

    // You call your friend to swap the magic numbers.
    swapNumbers(&x, &y);

    // Now, the magic numbers have switched places.
    cout << "After swapping: x = " << x << ", y = " << y << endl;



return 0;

}