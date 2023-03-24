#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>

void sig_handlerSIGALRM(int signum)
{
	printf ("\nALarma recibida");
	exit(1);

}
void sig_handlerSIGKILL(int signum)
{
}

int main () {
	signal(SIGALRM,sig_handlerSIGALRM);
	signal(SIGKILL,sig_handlerSIGKILL);
	pid_t pidB, pidC;
	int status;
	int i =0;
	
	pidB = fork();
	if (pidB==0) {
		pidC = fork();
		if (pidC==0) {
			while (i==0) {
				printf("Esperando una signal	");
			} //end while
		} //end if
		sleep(1);
		kill(pidC,SIGKILL);
		pause();
	} //end if
	
	alarm(5);
	waitpid(pidB,&status,0);

	return 0;
} //end main
