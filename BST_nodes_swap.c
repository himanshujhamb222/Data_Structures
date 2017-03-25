#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int*b)
{
        int temp=*a;
        *a=*b;
        *b=temp;
}
struct node
{
        int data;
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
void C_BST(struct node*root,struct node**prev,struct node**last,struct node**first)
{
    if(*prev!=NULL && (*prev)->data>root->data)
    {
            if(*first==NULL)
            {
                    *first=*prev;
            }
        
              *last=root;
    }
    *prev=root;
    
}
void Inorder(struct node*root,struct node**prev,struct node**last,struct node**first)
{
        if(root!=NULL)
        {
           Inorder(root->left,prev,last,first);
           C_BST(root,prev,last,first);
           Inorder(root->right,prev,last,first);
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
    struct node *root =   c_node(10);
    root->left        =   c_node(15);
    root->right       =   c_node(5);
    root->left->left  =   c_node(4);
    root->left->right =   c_node(7);
    root->right->right =  c_node(17);
    root->right->left =   c_node(14);
 
    struct node*prev=NULL;
    struct node*first=NULL;
    struct node*last=NULL;
    printInorder(root);
     Inorder(root,&prev,&last,&first);
     
     if(first!=NULL && last!=NULL)
    {
            swap(&first->data,&last->data);
        
    }
 
 
    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
 
    return 0;
}