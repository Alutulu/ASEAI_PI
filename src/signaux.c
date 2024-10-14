#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

// Lancer le programme dans un terminal, avec "&" pour que ce soit plus beau, et envoyer des signaux avec sigkill vers le process

// Attention, il y a des segmentation fault après avoir envoyé un signal;

/* declarations */
void signalHandler(int);

/* signal handler */
void signalHandler(int signal) {
    if(signal == SIGUSR1) {
        printf("HELLO !\n");
    }
}

int main(void) {
    struct sigaction sa, sa_old;
    sigset_t mask;
    sigemptyset(&mask);
    memset(&sa, 0, sizeof(sigaction));
    memset(&sa_old, 0, sizeof sigaction));
    sa.sa_handler = signalHandler;
    sa.sa_mask = mask; /* check !*/
    sigaction(SIGUSR1, &sa, NULL);
    do {
        continue; /*wait for signal*/
    } while(1);
    return 0;
}