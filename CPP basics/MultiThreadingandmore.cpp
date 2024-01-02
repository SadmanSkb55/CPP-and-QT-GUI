#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;
void threadFunction1() {
    for (int i = 0; i < 5; ++i) {
        cout << "Thread 1: " << i <<endl;
    }
}
void threadFunction2() {
    for (int i = 0; i < 5; ++i) {
        cout << "Thread 2: " << i <<endl;
    }    
}
class trunner{
    public:
        void threadfunction3(){
            for (int i = 0; i < 5; ++i) {
        cout << "Thread 3 from class: " << i <<endl;
            }
        }    
};
class FileHandler {
public:
    // Constructor acquires the file resource
    FileHandler(const std::string& fileName) : file(fileName) {
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file.");
        }
        std::cout << "File opened.\n";
    }
    // Destructor releases the file resource
    ~FileHandler() {
        file.close();
        std::cout << "File closed.\n";
    }
    void writeToFile(const std::string& content) {
        file << content;
    }

private:
    std::ofstream file;
};
int main() {
    // Get the current time before the code section
    auto start_time = std::chrono::high_resolution_clock::now();
    trunner tx;
    thread t1(threadFunction1);
    thread t2(threadFunction2);
   // Create trunner object and pass its member function to thread
    thread t3(&trunner::threadfunction3, &tx);
    t1.join();
    t2.join();
    cout << "Main thread exiting." <<endl;
     try {
        // FileHandler object is created and manages the file resource
        FileHandler fileHandler("Text.txt");
        fileHandler.writeToFile("Hello, RAII!");
        // The file will be closed automatically when fileHandler goes out of scope.
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    // Get the current time after the code section
     auto end_time = std::chrono::high_resolution_clock::now();
     // Calculate elapsed time
     // Calculate the duration (elapsed time) in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    // Output the duration
    std::cout << "Runtime: " << duration.count() << " microseconds\n";
    return 0;
}

