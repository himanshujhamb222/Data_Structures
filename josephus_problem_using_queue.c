#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int front=-1;
int rear=-1;
int size(int n)
{
	return (n-front+rear)%n;
}
bool IsEmpty()
{
	if(front==rear)
	{
		return true;
	}
	return false;
}
void enqueue(int x,int*a,int n)
{
    if(size(n)==n-1)
    
    {
        printf("Queue is full\n");
    }
    else if(IsEmpty())
    {
    	front=rear=0;
    	a[rear]=x;
    	rear=(rear+1)%n;
    }
    else
    {
        a[rear]=x;
        rear=(rear+1)%n;
       
    }
    
}
int dequeue(int*a,int n)
{   
	
    int data;
    if(!IsEmpty())
    {
        data=a[front];
        front=(front+1)%n;   
         return data;  
    }
    else
    {
    	printf("Quueue is empty\n");
    }
   
}
int main()
{
	int n,k,i,data,l,j,m,p,q;
	int*a;
	scanf("%d %d",&n,&k);
	m=n+1;
	a=(int*)malloc(sizeof(int)*m);
	for(i=1;i<=n;i++)
	{
		enqueue(i,a,m);
	}
	while(size(m)!=1)
	{
		for(i=1;i<k;i++)
		{
			data=dequeue(a,m);
			enqueue(data,a,m);
		}
		
		l=dequeue(a,m);
		
			p=0;q=front;
		   while(p<size(m))
		   {
		   		
			printf("%d ",a[q]);
			q=(q+1)%m;
			p++;
		  }
		printf("\n");
	}
	printf("survivor=%d\n",dequeue(a,m));
}
	



