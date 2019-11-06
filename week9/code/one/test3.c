#include "one.h"

static void __attribute__((constructor)) before_main()
{
  printf("Before test3 main!\n");
}

static void callback1(void)
{
  printf("callback1 is running!\n");
}

static void callback2(void)
{
  printf("callback2 is running!\n");
}

static void callback3(void)
{
  printf("callback3 is running!\n");
}

int main(int argc, char *argv[]){
  int i;
  atexit(callback1);
  atexit(callback2);
  atexit(callback3);
  printf("test3:pid=%d, ppid=%d\n", getpid(), getppid());
  for(i=0; i<argc; i++)
  printf("test3:%d: %s\n", i, argv[i]);
  while(1){
  sleep(1);
}
  return 0; 
}

