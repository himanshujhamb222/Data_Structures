#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void push(int x,int*stack,int*top)
    {
        stack[*top]=x;
        (*top)++;
    }
int pop(int*stack,int*top)
{
        (*top)--;
        return stack[*top];
}
void enqueue(int x,int*stack1,int*top)
{
    push(x,stack1,top);   
}

int dequeue(int*stack1,int*stack2,int*top1,int*top2)
{
      int l;
        if(*top2==0)
            {
                while(*top1!=0)
                 {
                    l=pop(stack1,top1);
                    push(l,stack2,top2);
                }
               return pop(stack2,top2);
            }
       else
             {
            
                  return pop(stack2,top2);  
            }
}
void print(int*stack1,int*stack2,int*top1,int*top2)
    {
        int l;
    
        if(*top2!=0)
         {
               printf("%d\n",stack2[*top2-1]); 
         }
        else
             {
                while(*top1!=0)
                 {
                    l=pop(stack1,top1);
                    push(l,stack2,top2);
                }
                printf("%d\n",stack2[*top2-1]);
             }
}


int main() 
{
    int q,i,type,x,top1=0,top2=0;
    int *stack1,*stack2;
    scanf("%d",&q);
    stack1=(int*)malloc(sizeof(int)*q);
    stack2=(int*)malloc(sizeof(int)*q);
    for(i=0;i<q;i++)
        {
            scanf("%d",&type);
            if(type==1)
                 {
                    scanf("%d",&x);
                    enqueue(x,stack1,&top1);
                 }
            if(type==2)
                {
                    dequeue(stack1,stack2,&top1,&top2);
                }
            if(type==3)
               {
                    print(stack1,stack2,&top1,&top2);
               }
        
        }  
    
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
