#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        int depth;
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
int min(int a,int b)
{
    if(a<=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int find_min_depth(struct node*root)
{
    if(root->left==NULL && root->right==NULL)
    {
        root->depth=1;
        return root->depth;
    }
     if(root->left!=NULL &&root->right==NULL)
    {
        root->depth=find_min_depth(root->left)+1;
        return root->depth;
    }
     if(root->right!=NULL &&root->left==NULL)
    {
        root->depth=find_min_depth(root->right)+1;
        return root->depth;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        root->depth=min(find_min_depth(root->left),find_min_depth(root->right))+1;
        return root->depth;
    }
   return root->depth;
}

int main()
{
     struct node *root = c_node(1);
    root->left = c_node(2);
    root->right = c_node(3);
    root->left->left = c_node(4);
    root->left->right = c_node(5);
   int l=find_min_depth(root);
    printf("%d ",l);
}





