#include"my.h"     

int tickets = 100;
pthread_mutex_t mutex;                 
pthread_cond_t q=PTHREAD_COND_INITIALIZER;
void *worker0(void *arg)
{
	pthread_mutex_lock(&mutex);     
	while(tickets > 0)
	{
		if(tickets%2==0)
		{
			usleep(1000);
			printf("worker0 read ticket : %d\n",tickets--);
			pthread_cond_signal(&q);
		}else
		{
			pthread_cond_wait(&q,&mutex);       
		}
		pthread_mutex_unlock(&mutex);    
	}
	
	return NULL;
}

void *worker1(void *arg)
{
	pthread_mutex_lock(&mutex);     
	while(tickets > 0)
	{
		if(tickets%2!=0)
		{
			usleep(1000);
			printf("worker1 read ticket : %d\n",tickets--);
			pthread_cond_signal(&q);
		}else
		{
			pthread_cond_wait(&q,&mutex);       
		}
		pthread_mutex_unlock(&mutex);    
	}
	
	return NULL;
}

int main()
{
	pthread_t tid[2];
	int i,ret;
	void *(*pt[2])();
	
	pt[0]=worker0;
	pt[1]=worker1;
	
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&q,NULL);
	for(i=0;i<2;i++)
	{
		ret = pthread_create(&tid[i],NULL,pt[i],NULL);
		if(ret!=0)
		{
			perror("create thread!\n");
			exit(1);
		} 
	}
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}
