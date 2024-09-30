/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ // Signal handler
    printf("Hello World!\n");
    alarm(5); // Schedule the next SIGALRM in 5 seconds
}

int main(int argc, char *argv[])
{
    signal(SIGALRM, handler); // Register handler for SIGALRM
    alarm(5); // Schedule the first SIGALRM in 5 seconds

    while (1) {
        pause(); // Wait for signal
        printf("Turing was right!\n");
    }

    return 0;
}
