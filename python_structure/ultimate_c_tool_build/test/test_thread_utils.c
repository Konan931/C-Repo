// Test file for test_thread_utils.c

#include <stdio.h>
#include <unistd.h>
#include "../include/thread_utils.h"

void *thread_func(void *arg) {
    printf("Thread running! Arg: %s\n", (char *)arg);
    return NULL;
}

int main(void) {
    printf("== Thread Utils Tests ==\n");
    start_thread(thread_func, "HelloThread");
    sleep(1); // Give thread time to run
    printf("All thread_utils tests done!\n");
    return 0;
}
