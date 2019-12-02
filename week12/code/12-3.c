#include "my.h"
int main()
{
  pid_t p1, p2, p3;
  int s1, s2, s3, rn, wn, fd1[2], fd2[2];
  char rbuf[1], wbuf[1];
  memset(rbuf, 0, sizeof(rbuf));
  memset(wbuf, 0, sizeof(wbuf));
  pipe(fd1);
  p1=fork();
  if(p1<0)
  {
    perror("fork failed!\n");
    return -1;
  }
  else if(p1 == 0)
  { 
    int i;
    close(fd1[0]);
    sprintf(wbuf, "1");
    for(i=0; i<10; i++)
    {
      write(fd1[1], wbuf, sizeof(rbuf));
      printf("child %d writes to pipe1!\n", getpid());
    }
    close(fd1[1]);
    printf("[child %d]\t[parent %d]\n", getpid(), getppid());
    exit(9);
  }
  else
  {
    pipe(fd2);
    p2=fork();
    if(p2<0)
    {
      perror("fork failed!\n");
      return -1;
    }
    else if(p2 == 0)
    {
      waitpid(p1, &s1, 0);
      close(fd1[1]);
      close(fd2[0]);
      while(1)
      {
        rn = read(fd1[0], rbuf, sizeof(rbuf));
        printf("[child %d] read form pipe1!\n", getpid());
        write(fd2[1], rbuf, sizeof(rbuf));
        printf("[child %d] write to pipe2!\n", getpid());
        if(rn == 0)
        {
          printf("[child1] read error!\n");
          break;
        }
      }
      close(fd1[0]);
      close(fd2[1]);
      printf("[child %d]\t[parent %d]\n", getpid(), getppid());
      exit(19);
    }
    else
    {
      p3=fork();
      if(p3<0)
      {
        perror("fork failed!\n");
        return -1;
      }
      else if(p3 == 0)
      {
        waitpid(p1, &s1, 0);
        close(fd2[1]);
        while(1)
        {
          rn = read(fd2[0], rbuf, sizeof(rbuf));
          printf("[child %d] read %s form pipe2!\n", getpid(), rbuf);
          if(rn == 0)
          {
            printf("[child2] read error!\n");
            break;
          }
        }
        close(fd2[0]);
        printf("[child %d]\t[parent %d]\n", getpid(), getppid());
        exit(99);
      }
      else
      {
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        p1=wait(&s1);
        p2=wait(&s2);
        p3=wait(&s3);
        printf("%d exit code %d\n%d exit code %d\n%d exit code %d\n", p1,WEXITSTATUS(s1), p2, WEXITSTATUS(s2), p3, WEXITSTATUS(s3));
        return 0;
      }
    }
  }
}
