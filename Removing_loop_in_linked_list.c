/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
    
      Node* ptr1 = node;
      Node* ptr2=node;
      Node*ptr3;
     
    while(ptr1 != NULL && ptr2->next!= NULL && ptr2->next->next!=NULL) 
    {
        ptr2 = ptr2->next->next;
     
        if(ptr2== ptr1) 
        {
            ptr3=ptr2;
            while(ptr3->next!=ptr2)
            {
                ptr3=ptr3->next;
            }
            ptr3->next=NULL;
            return;
        }
        ptr1=ptr1->next;
    }
    
    return ;
}
