#include"my.h"
int arg=0;
void foo(void *arg)
{
	struct sendval * k=(struct sendval *)arg;		
	
	struct timeval tv1,tv2;
	struct timezone tz;
	
	int sum=0,i;
	gettimeofday(&tv1,&tz);
	for(i=0;i<k->s;i++)
	{
		sum+=i;
	}
	gettimeofday(&tv2,&tz);
	k->time = tv2.tv_usec-tv1.tv_usec;
	
}

int main()
{
	pthread_t tid[NUM];
	int rev[NUM],**pt, i;
	struct sendval d;
	for(i=0;i<NUM;i++)
	{
		d.n=i;
		d.s=100*(i+1);
		d.time=0;
		rev[i] = pthread_create(&tid[i],NULL,(void *(*)())foo,(void *)&d);
		if(rev[i] != 0)
		{
			perror("thread failed!\n");
			exit(-1);
		}
		
		pthread_join(tid[i],(void **)&pt);
		printf("master %d : arg=%d,sum=%d\n",i,arg,**pt);
	}
	
}
