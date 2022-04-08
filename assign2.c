#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	char data[512];
};

int main()
{
 struct msgbuf v;
 struct msqid_ds buf;
 int id;

 id = msgget(55, IPC_CREAT|0644);
 printf("id: %d\n", id);

 v.mtype=25;
 strcpy(v.data, "amey");
 msgsnd(id, &v, strlen(v.data)+1, 0);

 msgctl(id, IPC_STAT, &buf);
 printf("no of msg's in q: %hi\n", buf.msg_qnum);
 printf("no of bytes: %hi\n", buf.msg_cbytes);
 printf("max no of bytes: %hi\n", buf.msg_qbytes);

 int i = msgctl(id, IPC_RMID, &buf);
 printf("Value: %d\n", i);

 return 0;
}
