#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>&Array);
int main(){

    double num=2.98;
    string name;
    bool booln;
    char grades[]={'a','A'};


    cout<<sizeof(num)<<endl;
    cout<<sizeof(name)<<endl;
    cout<<sizeof(booln)<<endl;
    cout<<sizeof(grades)/sizeof(char)<<endl;

    vector<int> Array;
    int input;
    cout<<"Enter some integer elements(Non integer will stop it)"<<endl;
    while (cin>>input)
    {
        Array.push_back(input);
    }
    cout<<"Entered Integers : ";
     for (int i : Array) {
        cout << i << " ";
    }
    std::cout << std::endl;
    int size=sizeof(Array)/sizeof(Array[0]);
    sort(Array);
    cout<<"After Sorted(lower to upper)"<<endl;
    for (int i : Array) {
        cout << i << " ";
    }
    
return 0;
}
void sort(vector<int>&Array){
    int temp;
    for (size_t i = 0; i < Array.size()-1; i++)
    {
       for (int j = 0; j < Array.size()-i-1; j++)
       {
        if (Array[j]>Array[j+1])
        {
            temp=Array[j];
            Array[j]=Array[j+1];
            Array[j+1]=temp;
        }
        
       }
       
    }
    
}