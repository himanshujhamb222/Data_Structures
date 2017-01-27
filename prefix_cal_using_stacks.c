#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=0;
void push(char x,char*A)
{
    
    A[top]=x;
    
    top++;
}
char pop(char*A)
{       
        top--;
        return A[top];
        
    
}
int cal(int x,char c,int y)
{
        if(c=='-')
        {
            return x-y;
        }
        else if(c=='+')
        {
            return x+y;
        }
        else if(c=='/')
        {
            return x/y;
        }
        else if(c=='*')
        {
            return x*y;
        }

    return 0;
}
int cal_prefix(char*exp)
{
      int result,el1,el2,i;
      char*stack=(char*)malloc(sizeof(char)*strlen(exp));
      for( i=0;i<strlen(exp);i++)
     {		
		if(exp[i]>='0' &&exp[i]<='9')
		{
			push(exp[i]-'0',stack);
		}
		
		if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*')
		{
		    el1=pop(stack);
		    el2=pop(stack);
		    result=cal(el2,exp[i],el1);
		    push(result,stack);
		}
    }
    return result;
}
int main()
{
	int n,result,i;
	scanf("%d",&n);
	char*exp=(char*)malloc(sizeof(char)*n);
	for( i=0;i<n;i++)
	{
		scanf("\n%c",&exp[i]);
	}
	result=cal_prefix(exp);
	printf("%d\n",result);
}