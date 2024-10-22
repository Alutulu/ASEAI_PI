#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include "MyGPIO.h"

// Le motor requiert 2 IN, qui sont constamment opposés. On choisit ici le port 17 et 18
// Attention, la période doit être longue, sinon le moteur ne tourne pas (c'est ce modèle précis)

/*declarations*/
void SignalHandler(int);

/*global*/
int last = 0;

/*signal handler (digital clock...)*/
void SignalHandler(int signal)
{

	if (signal == SIGALRM)
	{
		if (last == 0)
		{
			last = 1;
		}
		else
		{
			last = 0;
		}
		GPIOWrite(17, last);
		GPIOWrite(18, last == 1 ? 0 : 1);
	}
}

// int main(void){
// 	last = 0;
// 	GPIOInit(17);
// 	GPIOSetDir(17,0);
// 	GPIOInit(18);
// 	GPIOSetDir(18,0);

// 	struct sigaction sa, sa_old;
// 	struct itimerval t;
// 	sigset_t mask;

// 	t.it_interval.tv_sec = 15;
// 	t.it_interval.tv_usec = 0;
// 	t.it_value.tv_sec=15;
// 	t.it_value.tv_usec=0;
// 	memset(&sa,0,sizeof(struct sigaction) );
// 	memset(&sa_old,0,sizeof(struct sigaction) );
// 	sigemptyset(&mask);
// 	sa.sa_handler=SignalHandler;
// 	sa.sa_mask=mask/*check*/;
// 	sigaction(SIGALRM,&sa,&sa_old);
// 	setitimer(ITIMER_REAL,&t,NULL);
// 	do{
// 		pause();
// 	} while(1);
// 	return 0;
// }
