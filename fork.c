#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

/* Abel here will kill his old brother cain */

int main(void){
	pid_t pid_parent, pid_cain, pid_abel;
	int fd [2], n , kill_ret;
	
	pid_parent = getpid();
	if( (pid_cain = fork()) == 0){ /* cain */
		pid_parent = getppid();
		pid_cain = getpid();
		printf("cain : PIDparent=%i - PIDcain=%i \n",pid_parent, pid_cain);
		for(n=0;n<10;n++){
			printf("cain: %d/9 sec old. \n",n);
			sleep(1);
		}
		printf("cain last breath.. \n",n);
	}
	else    /* parent */ 
	{
		sleep(3);
		if( (pid_abel = fork()) > 0){ /* parent */
			printf("AdamEva: PIDparent=%i - PIDcain=%i - PIDabel=%i \n", pid_parent,pid_cain,pid_abel);
			sleep(10);
		}
		else{ /* abel */
			pid_abel = getpid();
			printf("Abel : PIDparent=%i - PIDcain=%i - PIDabel = %i \n",pid_parent,pid_cain,pid_abel);
			for(n=0;n<7;n++){
				printf("Abel : %d/6 sec old \n", n);
				sleep(1);
				if(n==3){
					kill_ret = kill(pid_cain,1);
					if(kill_ret == 0)
						printf("Abel : cain is killed ! \n");
					else
						printf("killing problem ! \n");
			}
		}
		printf("abel las breath.. \n");
	}
}
return(0);
}
