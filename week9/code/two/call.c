#include "two.h"

int main(){
  char *vector[]={"test4", "123", "456", NULL};
  printf("call:pid=%d, ppid=%d\n", getpid(), getppid());
  execvp("test4", vector);
  printf("------after calling------\n");
  return 0;
}
