#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H

#include <pthread.h>

void start_thread(void *(*func)(void *), void *arg);

#endif