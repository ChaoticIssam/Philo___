# Threads

A really helpfull definition of threads (based on OpenAi resources):

In the context of C programming language, a thread can be defined as a separate flow of execution that can run concurrently with other threads in the same process. 
A thread is also known as a lightweight process as it shares the same memory space as the main process and other threads within the same process, 
which allows for efficient communication and synchronization between threads.

Each thread has its own program counter, stack, and registers, which enables it to perform its own independent tasks while sharing resources with other threads. 
Threads can be used to perform parallel processing and improve the overall performance of an application.

In C, threads are implemented using a set of library functions that allow the programmer to create, start, stop, and manage threads. These functions are typically included in the "pthread.h" header file and are part of the POSIX (Portable Operating System Interface) standard.
