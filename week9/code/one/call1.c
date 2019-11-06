#include "one.h"

int main(){
  int ret;
  printf("call1:pid=%d, ppid=%d\n", getpid(), getppid());
  ret = system("./test1 123 456");
  printf("After calling! ret=%d\n", ret);
  sleep(5);
  return 0;
}
