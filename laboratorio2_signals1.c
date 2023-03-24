#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 
void sig_handler(int signum)
{
  printf("El usuario presiono CTRL+C\n");
  sleep(3);
  
} //end sig_handler
 
int main()
{ 
  signal(SIGINT,sig_handler); // Register signal handler
  int i = 0;
  while (i==0) {
  	printf("%d	", getpid());
  } //end while
  return 0;
}
