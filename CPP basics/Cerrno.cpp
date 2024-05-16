#include <cerrno>
#include <cstring>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

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
