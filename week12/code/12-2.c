#include "my.h"

int main()
{
    pid_t p;
    int fd[2], rn, wn;
    char rbuf[1], wbuf[1];
    memset(rbuf, 0, sizeof(rbuf));
    memset(wbuf, 0, sizeof(wbuf));
    pipe(fd);
    p=fork();
    if(p<0)
    {
      perror("fork failed!\n");
      return -1;
    }
    else if(p==0)
    {
      int i;
      close(fd[0]);
      sprintf(wbuf, "1");
      for(i=0; i<65536; i++)
      {
        write(fd[1], wbuf, sizeof(rbuf));
        printf("%d\n", i);
      }
      close(fd[1]);
      exit(0);
    }
    else
    {
      wait(NULL);
      close(fd[1]);
      while(1)
      {
        rn=read(fd[0], rbuf, sizeof(rbuf));
        printf("[parent] read from pipe %dbyte!Conten of pipe is %s\n",rn,rbuf);
        if(rn==0)
        {
          printf("[parent] read error! \n");
          break;
        }
      }
      close(fd[0]); 
      return 0;
    }
}
