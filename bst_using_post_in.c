#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node*c_node(int x)
{
    struct node*q=(struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}
int search(int arr[],int start,int end,int x)
{
    int i;
    for(i=start;i<=end;i++)
    {
        if(arr[i]==x)
        {
            break;
        }
    }
    return i;
}
struct node*BuildTree(int in[],int post[],int start,int end,int*pindex)
{
    
     if(start>end)
    {
        return NULL;
    }
    
    struct node*root=c_node(post[*pindex]);
      
    *pindex=*pindex-1;
    
     if(start==end)
    {
        return root;
    }
    
    int ino=search(in,start,end,root->data);
   
    root->right=BuildTree(in,post,ino+1,end,pindex);
    root->left=BuildTree(in,post,start,ino-1,pindex);
   return root;
}
struct node*build(int in[],int post[],int n)
{
    int pindex=n-1;
    
    return BuildTree(in,post,0,n-1,&pindex);
    
}
void preorder(struct node*root)
{
    if(root!=NULL)
    {
         printf("%d ",root->data);
       
        preorder(root->left);
         
        
         
        preorder(root->right);
    
    }
}
int main()
{
     int n;
     struct node*root;
     int in[]=  {4, 8, 2, 5, 1, 6, 3, 7};
     int post[]={8, 4, 5, 2, 6, 7, 3, 1};
     n=sizeof(in)/sizeof(in[0]);
     root=build(in,post,n);
     
     preorder(root);    
}