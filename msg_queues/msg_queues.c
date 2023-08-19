#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define OPTION_STRING "cdist:l:r"
#define MSGMAX 8192


#define ERR_EXIT(m) \
    do  \
    {   \
        perror(m);  \
        exit(EXIT_FAILURE); \
    }while(0);  

struct msgbuf {
    long mtype;
    char mtext[1024];
};

void help(char *argv[])
{
    fprintf(stderr,"Usage:%s [-c]\n",argv[0]);
}

int msg_queues_create(key_t key)
{
    int msgid;
    msgid = msgget(key, 0666 | IPC_CREAT | IPC_EXCL);
    if (msgid == -1)
        ERR_EXIT("msgget");
    
    printf("msg queues create success.\n");
    printf("msgid = %d\n",msgid);
    return msgid;
}

int msg_queues_delete(key_t key)
{
    int msgid;
    int ret;
    msgid = msgget(key,0);
    if (msgid == -1)
        ERR_EXIT("msgget");
    
    ret  = msgctl(msgid, IPC_RMID, NULL);
    if (ret == -1)
        ERR_EXIT("msgctl");

    printf("msg queues delete success.\n");
    printf("msgid = %d\n",msgid);
    return 0;
}

int msg_queues_info(key_t key)
{
    int msgid;
    int ret;
    struct msqid_ds buf;

    msgid = msgget(key,0);
    if (msgid == -1)
        ERR_EXIT("msgget");

    ret  = msgctl(msgid, IPC_STAT, &buf);
    if (ret == -1)
        ERR_EXIT("msgctl");
        
    printf("msgid = %d\n",msgid);
    printf("mode = %o\n",buf.msg_perm.mode);
    printf("number = %ld\n",buf.msg_qnum);
    printf("msg_cbytes = %ld\n",buf.msg_cbytes);
    printf("msg_qbytes = %ld\n",buf.msg_qbytes);
    return 0;
}

int msg_queues_change(key_t key)
{
    int msgid;
    int ret;
    struct msqid_ds buf;

    msgid = msgget(key,0);
    if (msgid == -1)
        ERR_EXIT("msgget");

    ret  = msgctl(msgid, IPC_STAT, &buf);
    if (ret == -1)
        ERR_EXIT("msgctl");
    sscanf("600","%o",&buf.msg_perm.mode);

    ret  = msgctl(msgid, IPC_SET, &buf);
    if (ret == -1)
        ERR_EXIT("msgctl");

    return 0;
}

int msg_queues_send(key_t key,long type,int len)
{
    int msgid;
    struct msgbuf *ptr;
    int ret;

    if (type == 0 || len == 0) {
        fprintf(stderr,"Usage: [-t] <tyep> [-l] <len>\n");
        return -1;
    }

    msgid = msgget(key,0);
    if (msgid == -1) {
        ERR_EXIT("msgget");
    }
    
    ptr = (struct msgbuf*)malloc(sizeof(long) + len);
    ptr->mtype = type;
    ptr->mtext[0] = 'h';
    ret = msgsnd(msgid, ptr, len, 0);
    if (ret == -1) {
        ERR_EXIT("msgsnd");
    }

    printf("msg queues send success.\n");
    printf("type = %ld len = %d.\n", type, len);
    return 0;
}

int msg_queues_read(key_t key,int type,int flag)
{
    int msgid;
    int len = 0;
    struct msgbuf *ptr;

    // if (type == 0 ) {
    //     fprintf(stderr,"Usage: [-t] <tyep> [-s]\n");
    //     return -1;
    // }

    msgid = msgget(key, 0);
    if (msgid == -1) {
        ERR_EXIT("msgget");
    }
    
    ptr = (struct msgbuf*)malloc(sizeof(long) + MSGMAX);
    ptr->mtype = type;
    if ((len = msgrcv(msgid, ptr, MSGMAX, type, flag)) < 0){
        ERR_EXIT("msgrcv");
    }
    
    printf("read %d bytes type = %ld\n", len, ptr->mtype);
    printf("msg: %c\n", ptr->mtext[0]);
}



int main(int argc,char *argv[])
{
    int msgid;
    int argflag;
    int ret;
    int type = 0;
    int len = 0;
    while((argflag = getopt(argc, argv, OPTION_STRING)) != -1)
    {
        switch (argflag) {
            case 'c':
                msgid = msg_queues_create(1234);
                break;
            case 'd':
                ret = msg_queues_delete(1234);
                break;
            case 'i':
                ret = msg_queues_info(1234);
                break;
            //case 's':
            //    ret = msg_queues_change(1234);
            //    break;
            case 't':
                type = atoi(optarg);
                break;
            case 'l':
                len = atoi(optarg);
                break;
            case 's':
                ret = msg_queues_send(1234,type,len);
                break;
            case 'r':
                ret = msg_queues_read(1234,type,IPC_NOWAIT);
                break;
            
            default:
                help(argv);
                exit(EXIT_FAILURE);
        }

    }
    exit(EXIT_SUCCESS);
}