#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    printf("Current Process ID: %d\n", pid);
    pid_t child = fork();
    for(int i = 0; i < 10; i++) 
    {

        if (child == 0) 
        {
            // Child process
            printf("Child Process ID: %d, Parent Process ID: %d\n", getpid());
        } 
        else 
        {
            // Parent process
            printf("Parent Process ID: %d, Child Process ID: %d\n", getpid(), child);
        }
    }
    return 0;
}