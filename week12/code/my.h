#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
#include <fcntl.h>

void sighandler(int);
