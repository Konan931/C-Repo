#include "../include/thread_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void start_thread(void *(*func)(void *), void *arg) {
    pthread_t tid;
    if (pthread_create(&tid, NULL, func, arg) == 0)
        pthread_detach(tid);
    else
        printf("Thread start failed\n");
}