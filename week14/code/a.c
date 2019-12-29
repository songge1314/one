#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
  struct timeval tv;
  struct timezone tz;
  gettimeofday(&tv,&tz);
  printf("s:%d ms:%d\n", (int)(tv.tv_sec), (int)(tv.tv_usec));
  sleep(2);
  gettimeofday(&tv,&tz);
  printf("s:%d ms:%d\n", (int)(tv.tv_sec), (int)(tv.tv_usec));  
  
}
