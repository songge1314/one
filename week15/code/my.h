#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define LOOP 10000000
#define NUM 4
#define TN 100
#define WRITER_FIRST
#define ARRAY_SIZE 1000
#define ARRAY_NUM 2

void initarray(int *a,int n) 
{ 
        int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		a[i] = (rand()%1000);
                //printf("a[%d]:%d\n",i,a[i]);
	}

}
