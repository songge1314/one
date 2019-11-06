#include "one.h"

int main(){
  char *arg[]={"test1", "123", "456", NULL};
  printf("call3 pid=%d, ppid=%d\n", getpid(), getppid());
  execlp("./test1", "test", "123", "456", NULL);
  //execv("./test1", arg);
  printf("execlp after calling!\n");
  return 0;
}
