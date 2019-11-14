#include "my.h"
int g=10;

int main()
{
   int l=20;
   int status;
   static int s=30;
   pid_t pid;
   pid=fork();
   if(pid <0)
     {
        perror("failed to fork!\n");
        return -1;
     }
   else if(pid==0)
     {
        int p=99;
        printf("-----address of var-----\n");
        printf("&g=%16p\n&l=%16p\n&s=%16p\n&p=%16p\n",&g,&l,&s,&p);
        g=100;
        l=200;
        s=300;
        p=99999;
        printf("value in child\n");
        printf("g=%d\nl=%d\ns=%d\np=%d\n",g,l,s,p);
        //return 0;
        exit(119);
        //_exit(0);
      }
   else
      {
        wait(&status);
        printf("exit code from child is %d\n",WEXITSTATUS(status));
        printf("-----address of var in parent-----\n");
        printf("parent :\n&g=%16p\n&l=%16p\n&s=%16p\n",&g,&l,&s);
        printf("value in parent\n");
        printf("parent :\ng=%d\nl=%d\ns=%d\n",g,l,s);
        return 0;
      }

}
