# System V进程间通信
## 相关指令
    ipcs
    ipcrm -q xxxid
    cat /proc/sys/kernel/msgmax
    cat /proc/sys/kernel/msgmnb
    cat /proc/sys/kernel/msgmni
## IPC对象的数据结构
内核为每个IPC对象维护一个数据结构
    struct ipc_perm {
        key_t          __key;       /* Key supplied to msgget(2) */
        uid_t          uid;         /* Effective UID of owner */
        gid_t          gid;         /* Effective GID of owner */
        uid_t          cuid;        /* Effective UID of creator */
        gid_t          cgid;        /* Effective GID of creator */
        unsigned short mode;        /* Permissions */
        unsigned short __seq;       /* Sequence number */
    };
# 消息队列
消息队列提供了进程向另一个进程发送一块数据的方法
消息最大长度（MSGMAX）、消息队列最大字节(MSGMNB)、消息队列数上线(MSGMNI)
## 消息队列的数据结构
    struct msqid_ds {
        struct ipc_perm msg_perm;   /* Ownership and permissions */
        time_t          msg_stime;  /* Time of last msgsnd(2) */
        time_t          msg_rtime;  /* Time of last msgrcv(2) */
        time_t          msg_ctime;  /* Time of creation or last
        modification by msgctl() */
        unsigned long   msg_cbytes; /* # of bytes in queue */
        msgqnum_t       msg_qnum;   /* # number of messages in queue */
        msglen_t        msg_qbytes; /* Maximum # of bytes in queue */
        pid_t           msg_lspid;  /* PID of last msgsnd(2) */
        id_t           msg_lrpid;  /* PID of last msgrcv(2) */
    };
## 消息队列的函数
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>
    int msgget(key_t key,int msgflg);
    int msgctl(int msqid,int cmd,struct msqid_ds *buf)
    int msgsend(int msqid,const void *msgp,size_t msgsz,
        msgflg);




