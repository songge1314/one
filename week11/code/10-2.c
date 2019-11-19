#include "my.h"
int main()
{
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
      perror("fail fork!\n");
      return -1;
    }
    else if(pid==0)
    {
      printf("child %d is running!\n", getpid());
      printf("child will exit!\n");
      while(1);
      exit(120);
    }
    else
    {
      printf("parent waiting child %d to exit!\n", pid);
      sleep(15);
      printf("parent %d is running!\n", getpid());
      return 0;
    }
}
