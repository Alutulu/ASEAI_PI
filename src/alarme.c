#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>

/* On se sert de ce code pour générer un signal carré de 200Hz with ~= 50% duty cycle (check the result with a scope)*/

/*globals*/
int hh, mm, ss, dd;

/*declarations*/
void SignalHandler(int);

/*signal handler (digital clock...)*/
void SignalHandler(int signal) {
    if (signal == SIGALRM) {
        dd++;
        if (dd == 10) {
            ss++;
            dd = 0;
            if (ss == 60) {
                mm++;
                ss = 0;
                if (mm == 60) {
                    hh++;
                    mm = 0;
                }
            }
        }
    }
}

/* program*/
int main(void) {
    struct sigaction sa, sa_old;
    struct itimerval t;
    sigset_t mask;

    hh = mm = ss = dd = 0;

    t.it_interval.tv_sec = 0;
    t.it_interval.tv_usec = 1e5; /*0.1 s*/
    t.it_value.tv_sec = 0;
    t.it_value.tv_usec = 1e5;

    memset(&sa, 0, sizeof(struct sigaction));
    memset(&sa_old, 0, sizeof(struct sigaction));
    sigemptyset(&mask);
    sa.sa_handler = SignalHandler;
    sa.sa_mask = mask;
    sigaction(SIGALRM, &sa, &sa_old);
    /* start the timer */
    setitimer(ITIMER_REAL, &t, NULL);

    do {
        pause();
        printf("%02d:%02d:%02d:%02d\n", hh, mm, ss, dd);
    } while(1);

    return 0;

}