#include "my.h"

int main(void)
{
    int status;
    FILE *fp;
    char buf1[]={"parent writes!\n"};
    char buf2[]={"child writes!\n"};
    if((fp=fopen("a.txt", "w+"))==NULL)
    {
      perror("failed to create file!\n");
      return -1;
    }
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
      perror("fork failed!\n");
      exit(-1);
    }
    else if(pid==0)
    {
      printf("child pid=%d,ppid=%d,fp=%p\n", getpid(),getppid(),fp);
      if(fputs(buf1,fp)==EOF)
      {
        perror("child failed to fputs file!\n");
      }
      else
      {
        printf("child fputs file!\n");
      }
      exit(0);     
    }
    else
    {
      wait(&status);
      printf("parent pid=%d,fp=%p\n",getpid(),fp);
      if(fputs(buf2,fp)==EOF)
      {
        perror("parent failed to fputs file!\n");
        exit(-1);
      }
      else
      {
        printf("parent fputs file!\n");
      }
      return 0;
    }
}
