 #include <iostream>
#include <cstdio>
using namespace std;
struct LLNode
{
    int data;
    LLNode *next;
};
void insertAtBeginning(LLNode**head,int dataToBeInserted)
{   LLNode*curr=new LLNode;
      curr->data=dataToBeInserted;
       curr->next=NULL;
    if(*head==NULL)
            *head=curr;

    else
        {  curr->next=*head;
            *head=curr;
        }
}
  void display(LLNode**head)
{
      LLNode*temp=*head;
    while(temp!=NULL)
        {            if(temp->next!=NULL)
            cout<<temp->data<<" ->";
            else
            cout<<temp->data;
             temp=temp->next;
        }
         cout<<endl;
}
  LLNode *getTail(LLNode *cur)
{    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
       LLNode *partition(LLNode *head, LLNode *end, LLNode **newHead, LLNode **newEnd)
{
    LLNode *pivot = end;
    LLNode *prev = NULL, *cur = head, *tail = pivot;
      while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {                       if (prev)
                prev->next = cur->next;
            LLNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
        if ((*newHead) == NULL)
        (*newHead) = pivot;
        (*newEnd) = tail;
    return pivot;
}
LLNode *quickSortRecur(LLNode *head, LLNode *end)
{
    if (!head || head == end)
        return head;
    LLNode *newHead = NULL, *newEnd = NULL;
    LLNode *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        LLNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next =  pivot;    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}
void quickSort(LLNode **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
int main()
{
    LLNode *head = NULL;
    LLNode *tail = NULL;
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 96);
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 54);
    insertAtBeginning(&head, 19);
    insertAtBeginning(&head, 28);
    cout << "Linked List before sorting \n";
    display(&head);
    quickSort(&head);
    cout << "Linked List after sorting \n";
    display(&head);
    return 0;
}
