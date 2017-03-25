#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int*b)
{
        int temp=*a;
        *a=*b;
        *b=temp;
}
int part(int*a,int p,int r)
{
        int i=p-1,j;

        int x=a[r];

    for(j=p;j<=r-1;j++)
    {
            if(a[j]<=x)
            {
                    i=i+1;
                    swap(&a[i],&a[j]);
            }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
void quicksort(int *a,int p,int r)
{
        if(p<r)
        {
                int q=part(a,p,r);
                quicksort(a,p,q-1);
                quicksort(a,q+1,r);
        }
}
int power2(int n)
{
        int i,l=1;
        for(i=0;i<n;i++)
        {
                l=l*2;
        }
        return l;
}
struct node
{
        int data;
        int x;
        int y;
        struct node*left;
        struct node*right;
};

struct node*c_node(int k)
{
        struct node*q=(struct node*)malloc(sizeof(struct node)*1);
        q->data=k;
        q->left=NULL;
        q->right=NULL;
        return q;
}
int **allocate_memory(int n,int m)
{
    int **a,i,j;
    a=(int **)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i]=(int*)malloc(sizeof(int)*m);
        }
    }
    return a;
}
struct node*build_tree(int *a,int start,int end,int height)
{
        if(start>end)
        {
                return NULL;
        }
        if(start==end)
        {
                struct node*q=c_node(a[start]);
                q->y=(start+end)/2;
                q->x=height;
                return q;
                
        }
        else
        {
                
                struct node*q=c_node(a[(start+end)/2]);
                q->y=(start+end)/2;
                q->x=height;
                q->left=build_tree(a,start,(start+end)/2-1,height+1);
                q->right=build_tree(a,(start+end)/2+1,end,height+1);
                return q;
        }
}

/*void Inorder(struct node*root)
{
    if(root!=NULL)
    {
      Inorder(root->left);
      printf(" %d %d %d ",root->x,root->y,root->data);
      Inorder(root->right);
    }
}*/
void print_tree(int**b,struct node*root)
{
        if(root!=NULL)
        {
                print_tree(b,root->left);
                b[root->x][root->y]=root->data;
                print_tree(b,root->right);
         }
}

int main()
{
        int *a,i,n,j,height=0;
        int**b;
        struct node*q;
        scanf("%d",&n);
        a=(int*)malloc(sizeof(int)*(power2(n)));
        b=allocate_memory(n,power2(n)-1);
        for(i=0;i<power2(n)-1;i++)
        {
                a[i]=rand()%100;
        }
        quicksort(a,0,power2(n)-2);
        q=build_tree(a,0,power2(n)-2,height);
        
        //initializing array b
         for(i=0;i<n;i++)
    {
        for(j=0;j<power2(n)-1;j++)
        {
           b[i][j]=-1;
        }
    }
      
        print_tree(b,q);
         for(i=0;i<n;i++)
       {
             for(j=0;j<power2(n)-1;j++)
            {
                       if(b[i][j]==-1)
                       {
                           printf("%c",' ');
                       }
                       else
                     {
                           printf("%d ",b[i][j]);
                     }
         }
        printf("\n");
    }


}