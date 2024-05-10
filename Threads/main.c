#include <stdio.h>
#include <threads.h> // Consider using <pthread.h> if you are using a different compiler

void* factorial(void*);

int main(void) {
    thrd_t thread1, thread2;
    long n1 = 4, n2 = 8;

    thrd_create(&thread1, (void *)factorial, (void*)(&n1)); // Create a thread, pass the function and the argument
    thrd_create(&thread2, (void *)factorial, (void*)(&n2));

    thrd_join(thread1, NULL); // Wait for the thread to finish, NULL is the return value of the thread
    thrd_join(thread2, NULL);
    return 0;
}

void* factorial(void* num) {
    long* n = (long*)num;
    long fac = 1;
    for (long i = 1; i <= *n; i++) fac *= i;
    printf("Factorial of %ld is %ld\n", *n, fac);
    return NULL;
}