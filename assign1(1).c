#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>

int main()
{
 int id;
 void *c;
 id = shmget(40, 250, IPC_CREAT|0644);
 printf("ID is %d\n", id);

 c = shmat(id, 0, 0);
 printf("Address is: %p\n", c);

 return 0;
}
