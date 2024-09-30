/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Global variables to track alarm count and start time
volatile sig_atomic_t alarm_count = 0;
time_t start_time;

void alarm_handler(int signum)
{
    // Print "Hello World!" when SIGALRM is received
    printf("Hello World!\n");
    alarm_count++;
    alarm(5); // Reschedule the SIGALRM for another 5 seconds
}

void sigint_handler(int signum)
{
    // Calculate the total time the program has been running
    time_t end_time;
    time(&end_time);
    double total_time = difftime(end_time, start_time);

    // Print total time executed and number of alarms triggered
    printf("\nTotal time executed: %.0f seconds\n", total_time);
    printf("Total alarms triggered: %d\n", alarm_count);

    exit(0);  // Exit program after handling SIGINT
}

int main(int argc, char *argv[])
{
    // Record the start time
    time(&start_time);

    // Register signal handlers
    signal(SIGALRM, alarm_handler);  // Handle SIGALRM (alarm every 5 seconds)
    signal(SIGINT, sigint_handler);  // Handle SIGINT (CTRL-C)

    // Schedule the first SIGALRM for 5 seconds
    alarm(5);

    // Infinite loop, waiting for signals
    while (1) {
        pause(); // Wait for a signal (SIGALRM or SIGINT)
        printf("Turing was right!\n");
    }

    return 0;
}
