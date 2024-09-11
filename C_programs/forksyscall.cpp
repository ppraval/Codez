#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() 
{
    pid_t pid = fork();

    if (pid < 0) 
    {
        // Fork failed
        printf("gay");
        return 1;
    } 
    else if (pid == 0) 
    {
        // Child process
        printf("gay1\n");
    } 
    else 
    {
        // Parent process
        printf("%d\n", pid);
        printf("gay2\n");
    }

    return 0;
}
