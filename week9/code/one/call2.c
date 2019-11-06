#include "one.h"

int main(){
  printf("call2 pid=%d, ppid=%d\n", getpid(), getppid());
  execl("./test1", "test1", "123", "456", NULL);
  printf("execl after calling!\n");
}
