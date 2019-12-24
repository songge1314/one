
#include "my.h"
int main()
{
    int i=1;
    int b=3;
    printf("&i:%d\n", &i);
    b = (int *)i;
    printf("(int *)i:%d\n",(int *)i);
    printf("i:%d\n",i);
    printf("&i:%d\n",&i);
}
