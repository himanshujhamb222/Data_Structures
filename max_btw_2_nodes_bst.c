#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node*left;
        struct node*right;
        struct node*parent;
};
struct node*c_node(int k)
{
        struct node*q=(struct node*)malloc(sizeof(struct node)*1);
        q->data=k;
        q->left=NULL;
        q->right=NULL;
        q->parent=NULL;
        return q;
}
struct node* Insert(struct node*root,int key)
{
    if(root==NULL)
    {
        return c_node(key);
    }
    if(key>root->data)
    {
               struct node*q=Insert(root->right,key);
               root->right=q;
               q->parent=root;
        
    }
     if(key<root->data)
    {
        struct node*q=Insert(root->left,key);
               root->left=q;
               q->parent=root;
    }
    return root;
}
struct node*Find_node(struct node*root,int key)
{
    if(key==root->data)
    {
        return root;
    }
     if(key<root->data)
    {
            return Find_node(root->left,key);
    }
    if(key>root->data)
    {
            return Find_node(root->right,key);
    }
    return NULL;
}
struct node*LCA(struct node*q1,struct node*q2)
{
    struct node*t=q1;
    struct node*s=q2;
    while(t!=s)
    {
        if(t->parent!=NULL)
        {
            t=t->parent;
        }
        if(s->parent!=NULL)
        {
            s=s->parent;
        }
    }
    return t;
}
void Max(struct node*LA,int a,int*max)
{
        if(LA->data==a)
        {
            if(*max<LA->data)
            {
                *max=LA->data;
            }
            return ;
        }
        if(LA->data>a)
        {
            Max(LA->left,a,max);
            
             if(*max<LA->left->data)
            {
                *max=LA->left->data;
            }
        }
         if(LA->data<a)
        {
           
            Max(LA->right,a,max);
            
             if(*max<LA->right->data)
            {
                *max=LA->right->data;
            }
        }
        
}
void printInorder(struct node*root)
{
        if(root!=NULL)
        {
           printInorder(root->left);
           printf("%d ",root->data);
           printInorder(root->right);
        }
}

int main()
{
     int arr[] = { 18, 36, 9 , 6, 12, 10, 1, 8 };
     int a = 1, b = 9;
     int n = sizeof(arr)/sizeof(arr[0]);
     int max1=0,max2=0;
 
    // Creating the root of Binary Search Tree
    struct node *root = NULL;
    
    //Find node having a,b,lca
    
    struct node*q1,*q2,*lca;
 
    // Inserting Nodes in Binary Search Tree
    for (int i = 0; i < n; i++)
      {
          root= Insert(root, arr[i]);
      }
        q1=Find_node(root,a);
        q2=Find_node(root,b);
        lca=LCA(q1,q2);
        Max(lca,a,&max1);
        Max(lca,b,&max2);
        if(max1>=max2)
        {
           printf("%d ",max1);
        }
        if(max1<max2)
        {
           printf("%d ",max2);
        }
}



