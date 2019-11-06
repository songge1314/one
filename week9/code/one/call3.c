#include "one.h"

int main(){
  char *arg[]={"test1", "123", "456", NULL};
  printf("call3 pid=%d, ppid=%d\n", getpid(), getppid());
  execv("./test1", arg);
  printf("execv after calling!\n");
  return 0;
}
