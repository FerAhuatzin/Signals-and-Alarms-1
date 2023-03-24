#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
 
void sig_handlerSIGUSR2(int signum)
{
	printf ("Recibi la signal SIGUSR2 el id del proceso que la recibio es %d con padre %d\n", getpid(), getppid());
}
void sig_handlerSIGUSR1(int signum)
{
	printf ("Recibi la signal SIGUSR1 el id del proceso que la recibio es %d con padre %d\n", getpid(), getppid());

}
void sig_handlerSIGALRM(int signum)
{
	printf ("Recibi la signal SIGALARM el id del proceso que la recibio es %d\n", getpid());

}
 
int main()
{ 
  signal(SIGALRM,sig_handlerSIGALRM);
  signal(SIGUSR1, sig_handlerSIGUSR1);
  signal(SIGUSR2, sig_handlerSIGUSR2);
  pid_t pidA;
  pid_t pidC;
  int status;
  
  
  pidA = fork();
  if(pidA==0){	
  	pause();
  	pidC = fork();
  	if (pidC == 0) {
  		pause();
  		return 0;
  	} //end pidC
  	
  	sleep(1);
  	kill(pidC,SIGUSR2);
  	waitpid(pidC, &status, 0);
  	return 0;
  	
  } //end pidA
  
  
  alarm(3);
  pause();
  kill(pidA,SIGUSR1);
  waitpid(pidA, &status, 0);
  printf("Mis hijos han funcionado\n");
  
 return 0; 
}
