#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node*left;
    struct node*right;
};
struct node*c_node(char x)
{
    struct node*q=(struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}
int search(char*in,int start,int end,char x)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==x)
        {
            return i;
        }
    }
    return 0;
}
struct node*BuildTree(char*in,char*pre,int start,int end)
{
    static int preorder=0;
    
    int ino=search(in,start,end,pre[preorder]);
     
    struct node*root=c_node(pre[preorder++]);
    
    if(start>end)
    {
        return NULL;
    }
    if(start==end)
    {
        return root;
    }
    root->left=BuildTree(in,pre,start,ino-1);
    root->right=BuildTree(in,pre,ino+1,end);
   return root;
}
void Inorder(struct node*root)
{
    if(root!=NULL)
    {
      Inorder(root->left);
      printf("%c ",root->data);
      Inorder(root->right);
    }
}
int main()
{
     int n;
     struct node*root=NULL;
     char*in,*pre;
     scanf("%d",&n);
     in=(char*)malloc(sizeof(char)*n);
     pre=(char*)malloc(sizeof(char)*n);
     
     for(int j=0;j<n;j++)
     {
         scanf(" %c%c",&in[j],&pre[j]);
         
     }
     root=BuildTree(in,pre,0,n-1);
     
     Inorder(root);    
}