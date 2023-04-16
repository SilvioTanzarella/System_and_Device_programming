#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Global variable to trace the last signals recevied*/

int last_sig = -1;
int last_last_sign = -1;
int finish = 0;

void sign_handler(int sign);

int main(int argc, char **argv[]){
    int pid1, pid2;
    char cmd[200];

    srand(time(NULL));
    
    //inistantiate the signal handler
    if((signal(SIGUSR1, sign_handler)== SIG_ERR) || (signal(SIGUSR2,sign_handler)==SIG_ERR)){
        printf("Error initializing signal handler");
        exit(-1);
    }

    pid1 = fork();
    if(pid1 == 0){
        //child1
        while(1){
            sleep(rand()%2);
            kill(getppid(), SIGUSR1);
        }
    }else{
        pid2=fork();
        if(pid2 == 0){
            //child2
            while(1){
                sleep(rand()%3);
                kill(getppid(), SIGUSR2);
            }
        }else{
            //Father
            while(1){
                pause();
                if(finish){
                    sprintf(cmd, "kill -9 %d", pid1);
                    system(cmd);
                    sprintf(cmd, "kill -9 %d", pid2);
                    system(cmd);
                    exit(0);
                }
            }
        }
    }
    return 0;
}

void sign_handler(int sig){
    //it receives a signal
    if(sig == SIGUSR1){
        if(!finish){
            printf("Signal received from P1\n");
        }
    }else if(sig == SIGUSR2){
        if(!finish){
            printf("Signal received from P2\n");
        }
    }

    if(last_last_sign == last_sig && last_sig == sig){
        finish = 1;
    }else{
        last_last_sign = last_sig;
        last_sig = sig;
    }
    return;
}
