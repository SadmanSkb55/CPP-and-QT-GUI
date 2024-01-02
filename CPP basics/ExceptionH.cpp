#include<iostream>
#include <stdexcept> 
// #include <Windows.h>
// #include <DbgHelp.h>

// #pragma comment(lib, "Dbghelp.lib")

using namespace std;

class mather{
    public:
    virtual double add(double a, double b) = 0; 
    virtual double subs(double a, double b) = 0; 
    virtual double mul(double a, double b) = 0; 
    virtual double div(double a, double b) = 0; 
};
class mathx : public mather {

    public:

    double add(double x, double y)override{ return x + y;}
    double subs(double x, double y)override{return x > y ? x - y : x + y;} 
    double div(double a, double b)override{
            if (b == 0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
     }
     double mul(double x , double y ) override{ return x * y ; }
    };
// void printStackTrace() {
//     const int max_frames = 10;
//     void* addrlist[max_frames];
//     HANDLE process = GetCurrentProcess();
//     SymInitialize(process, nullptr, TRUE);
//     USHORT frames = CaptureStackBackTrace(0, max_frames, addrlist, nullptr);

//     SYMBOL_INFO* symbol = (SYMBOL_INFO*)calloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char), 1);
//     symbol->MaxNameLen = 255;
//     symbol->SizeOfStruct = sizeof(SYMBOL_INFO);

//     for (USHORT i = 0; i < frames; ++i) {
//         SymFromAddr(process, (DWORD64)(addrlist[i]), 0, symbol);
//         std::cout << "  " << symbol->Name << "\n";
//     }

//     free(symbol);
// }
class ExceptroB : public std::exception {
public:
    const char* what() const noexcept override {
        return "This is a custom exception!";
    }
};

int main(){
    mather* m = new mathx();
    cout << m->add(2.4, 6.7) <<endl;
    cout << m->subs(3.8, 9.1) <<endl;
    try {
        cout << m->div(5.0, 0.0) <<endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught: " << e.what() << '\n';
       // printStackTrace();
    }
    cout << m->mul(6.7, 8.9) <<endl;
    int num;
    cout<<"Enter a number"<<endl;
    cin>>num;
    int num2;
    cout<<"Another number"<<endl;
    cin>>num2;

    try {
        throw ExceptroB();
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }


    delete m;
    return 0;
}


