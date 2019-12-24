#include"my.h"
//创建4个线程，第一个计算1-100的和，第二个计算1-200的和
//第三个计算1-300的和，第四个计算1-400的和
void *fun(void *arg)
{
	int sum;
	struct sendval * k=(struct sendval *)arg;
	int i=0;
	for(i=0;i<k->s;i++)
	{
		sum+=i;
	}
	printf("worker---%d : pthread_self return %p,sum of %d=%ld\n",k->n,(void*)pthread_self(),k->s,sum);
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t tid[NUM];
	int ret[NUM],i;
	struct sendval d;
	for(i=0;i<NUM;i++)
	{
		d.n=i;
		d.s=100*(i+1);
		ret[i] = pthread_create(&tid[i],NULL,fun,(void *)&d);
		if(ret[i] != 0)
		{
			perror("create failed!\n");
			return -1;
		}
		pthread_join(tid[i],NULL);
	}
	printf("Master %d  :  Alll done!\n",getpid());
	return 0;
}
