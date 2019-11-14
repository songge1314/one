#include "my.h"
int main()
{
    int a=0x1,i;
    
    for(i=0;i<=sizeof(int)*8;i++)
        {
         printf("%d: a = %16p ,%16ld ,%16u\n",i,a,a,a);
         a=a<<1;
        }
    
    return 0;
}
