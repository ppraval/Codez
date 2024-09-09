#include <iostream>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        std::cout << "This is the child process with PID: " << getpid() << std::endl;
    } else {
        // Parent process
        std::cout << "This is the parent process with PID: " << getpid() << " and child PID: " << pid << std::endl;
    }

    return 0;
}
