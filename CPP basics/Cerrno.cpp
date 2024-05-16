/**
 * @file main.cpp
 * @brief Demonstrates error handling using errno with file operations in C++.
 */

#include <cerrno>
#include <cstring>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

/**
 * @brief Main function to demonstrate file opening and error handling using errno.
 * 
 * This function attempts to open a file named "nonexistentfile.txt" in read-only mode.
 * If the file cannot be opened, it prints the error number and a human-readable error message.
 * If the file is successfully opened, it closes the file descriptor.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    int fd = open("nonexistentfile.txt", O_RDONLY);
    if (fd == -1) {
        int errnum = errno;
        std::cerr << "Error opening file: " << errnum << std::endl;
        std::cerr << "Error message: " << std::strerror(errnum) << std::endl;
    } else {
        close(fd);
    }
    return 0;
}
