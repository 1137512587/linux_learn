#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGMAX 8192

struct msgbuf {
    long mtype;
    char mtext[MSGMAX];
};

#define ERR_EXIT(m) \
    do  \
    {   \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0);  

void echo_cli(int msgid)
{   
    int pid;
    int len;
    struct msgbuf msg;

    memset(&msg, 0, sizeof(msg));
    pid = getpid();
    printf("pid = %d\n",pid);
    *(int*)msg.mtext = pid;
    msg.mtype = 1;
    while (fgets(msg.mtext + 4, MSGMAX - 4, stdin) != NULL) {

        msg.mtype = 1;
        if (msgsnd(msgid, &msg, 4 + strlen(msg.mtext + 4), 0) == 1) {
            ERR_EXIT("msgsnd");
        }

        memset(msg.mtext + 4, 0, MSGMAX - 4);
        msg.mtype = pid;
        if ((len = msgrcv(msgid, &msg, MSGMAX, pid, 0)) < 0) {
            ERR_EXIT("msgrcv");
        }
        fputs(msg.mtext + 4,stdout);
        memset(msg.mtext + 4, 0, MSGMAX - 4);
    }    
}

int main(int argc,char argv[])
{
    int msgid;
    msgid = msgget(1234,0);
    if(msgid == -1) {
        ERR_EXIT("msgget");
    }

    echo_cli(msgid);
    return 0;
}