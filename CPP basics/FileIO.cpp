#include <iostream>
#include <fstream>
#include <string>
#include<stdexcept>

using namespace std;
int main() {
    string fname,content;
cout<<"Enter File name with extension"<<endl;
cin>>fname;
cout<<"Enter some string to input in file"<<endl;
cin.ignore();
cin>>content;

    try
    {
        ofstream outputFile(fname,std::ios::app);//std::ios::app it wont let previous file to be delated
    if (outputFile.is_open()) {
        outputFile <<content<<"\n";
        outputFile.close();
        cout << "File "<<fname<<" written successfully.\n";
    } else {
    cerr << "Unable to open file for writing.\n";
        return 1;
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    string fname2;
    cout<<"Enter File name with extension which u want to read"<<endl;
cin>>fname2;
    try
    {
       std::ifstream inputFile(fname2);
    if (inputFile.is_open()) {
        string line;
        cout << "Contents of "<<fname2<<" are:"<<endl;;
        while (std::getline(inputFile, line)) {
            std::cout << line << "\n";
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file for reading.\n";
        return 1; 
    }
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    return 0;
}