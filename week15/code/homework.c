#include "my.h"
int A[ARRAY_SIZE];
int B[ARRAY_SIZE];
int maxnum;
int max[ARRAY_NUM]={0};
void *fun(void *param)
{
	int num = (int)param;
	int i=0;
	if(num == 0)
	{
		for(i=0;i<ARRAY_SIZE;i++)
		{
			max[num] = max[num]>A[i]?max[i]:A[i];
		}	
	}else
	{
		for(i=0;i<ARRAY_SIZE;i++)
		{
			max[num] = max[num]>A[i]?max[i]:A[i];
		}
	}
	
	return NULL;
}

int main()
{
	pthread_t tid[ARRAY_NUM];
	int i,ret;
	initarray(A,ARRAY_SIZE);
        initarray(B,ARRAY_SIZE);
	for(i=0;i<ARRAY_NUM;i++)
	{
		ret = pthread_create(&tid[i],NULL,fun,(void *)i);
		if(ret!=0)
		{
			perror("thread init failed!\n");
			exit(2);
		}
		pthread_join(tid[i],NULL);
	}
	
	maxnum = max[0]>max[1]?max[0]:max[1];
	printf("maxA----------%d\n",max[0]);
	printf("maxB----------%d\n",max[1]);
	printf("max-----------%d\n",maxnum);
	
}
