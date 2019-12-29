#include "my.h"
FILE *fp;
sem_t empty,full;
struct timeval tv;
struct timezone tz;
void *worker0(void *arg)
{
        int i;
        int n=(int)arg;
        int min=n*10000;
        int max=(++n)*10000;
        for(i=min;i<max;i++ )
        {
          sem_wait(&empty);
          gettimeofday(&tv,&tz);
          fprintf(fp,"work0:%d  time:%d.%d\n",i,(int)(tv.tv_sec),(int)(tv.tv_usec));
          sem_post(&full);
          pthread_yield();
        }
	return NULL;
}

void *worker1(void *arg)
{
        int i;
        int n=(int)arg;
        int min=n*10000;
        int max=(++n)*10000;
        for(i=min;i<max;i++ )
        {
          sem_wait(&empty);
          gettimeofday(&tv,&tz);
          fprintf(fp,"work1:%d  time:%d.%d\n",i,(int)(tv.tv_sec),(int)(tv.tv_usec));
          sem_post(&full);
          pthread_yield();
        }
        return NULL;
}


void *worker2(void *arg)
{
        int n=(int)arg;
        char buf[1024]={0};
        while(1)
        {
          sleep(1);
          sem_wait(&full);
          fscanf(fp,"%s",buf);
          printf("%s\n",buf);
          sem_post(&empty);
          pthread_yield();
        }
        return NULL;
 
}
int main()
{
	pthread_t tid[3];
	int i,ret;
	
	void*(*pt[3])();
	pt[0]=worker0;
	pt[1]=worker1;
        pt[2]=worker2;
	ret=sem_init(&empty,0,1);
	ret=sem_init(&full,0,0);
        fp=fopen("mydata.txt","a+");
	for(i=0;i<3;i++)
        {
       	  ret=pthread_create(&tid[i],NULL,pt[i],(void *)i);
	  if(ret!=0)
          {  
	    perror("create thread!\n");
	    exit(1);
          }
        }
	for(i=0;i<3;i++)
	pthread_join(tid[i],NULL);
	return 0;
	
}
