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
int prec(char x)
{
	if(x=='+'||x=='-')
	{
		return 1;
	}
	else if(x=='(')
	{
		return 0;
	}
	else if(x=='*'||x=='/')
	{
		return 2;
	}
	else if(x=='^')
	{
		return 3;
	}
	else
	{
		return -1;
	}
}
void infix_to_prefix(char*exp)
{
    
    char*out=(char*)malloc(sizeof(char)*strlen(exp));
	char*stack=(char*)malloc(sizeof(char)*strlen(exp));
	int j=0,i;
	for(i=0;i<strlen(exp);i++)
   {		
		if(exp[i]>='0' &&exp[i]<='9')
		{
			out[j]=exp[i];
			j++;
		}
		else if(exp[i]=='(')
		{
			push(exp[i],stack);
		}
		else if(exp[i]==')')
		{
			while(stack[top-1]!='(')
			{
				out[j]=pop(stack);
				j++;
			}
			if(top!=0)
			{
			  pop(stack);
			}
		}
	    else if(exp[i]=='+'|| exp[i]=='-' || exp[i]=='*' ||exp[i]=='/'||exp[i]=='^')
	   {
		     if(top==0)
		     {
			    push(exp[i],stack);
		     }
	  	     else if(prec(exp[i])>prec(stack[top-1]))
	  	     {
	  	
	  		   push(exp[i],stack);
	  	     }
	  	     else if(prec(exp[i])<=prec(stack[top-1]))
	  	      {
	  			  do
	  			  {
	  				  out[j]=pop(stack);
	  				  j++;
	  			  }
	  		      while(exp[i]<=stack[top-1] &&top!=0);
	  		 
	  		      push(exp[i],stack);
	  	      }
	      }
    }  
    
  while(top>=0)
	 {
	 	out[j]=pop(stack);
	 	j++;
	 }
	 for(i=0;i<j;i++)
	 {
	 	printf("%c",out[i]);
	 }
}


int main()
{
    int n,i;
	scanf("%d",&n);
	char*exp=(char*)malloc(sizeof(char)*n);
		for(i=0;i<n;i++)
	{
	
		scanf("\n%c",&exp[i]);
	}
	infix_to_prefix(exp);
}

		
	