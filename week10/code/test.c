#include "my.h"
int a[100]={0};
int g=99;

int main()
{
   int i;
   int l=99;
   static int k=20;
   for(i=0;i<10;i++)
      printf("%d : %d\n",getpid(),i);
   return 0;
}
