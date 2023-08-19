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

void echo_srv(int msgid)
{
    int pid;
    int len;
    int ret;
    struct msgbuf msg;
    memset(&msg, 0, sizeof(msg));
    while(1) {
        len = msgrcv(msgid, &msg, MSGMAX, 1, 0);
        if (len < 0) {
            ERR_EXIT("msgrcv");
        }
        printf("len = %d\n",len);
        //fputs(msg.mtext + 4, stdout);
        //fputs(msg.mtext, stdout);
        
        pid = *(int*)msg.mtext;
        fputs(msg.mtext + 4, stdout);
        msg.mtype = pid;
        printf("pid = %d\n",pid);
        ret = msgsnd(msgid, &msg, len, 0);
        if(ret == -1) {
            ERR_EXIT("msgsnd");
        }
    }
}

int main(int argc,char argv[])
{
    int msgid;
    msgid = msgget(1234, 0666 | IPC_CREAT);
    if(msgid == -1) {
        ERR_EXIT("msgget");
    }

    echo_srv(msgid);
}