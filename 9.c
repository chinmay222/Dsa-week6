#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

node* head;

int check_cycle()
{
    node *slow_p = head, *fast_p = head;
    while ((slow_p != NULL) && (fast_p != NULL) && ((fast_p->next)!= NULL) )
    {
        slow_p = slow_p->next;
        fast_p  = (fast_p->next)->next;
        if (slow_p == fast_p)
        {
           printf("\nFound Loop");
           return 1;
        }
    }
    printf("\nNo Loop");
    return 0;
}

void push(int new_data)
{
    node* new_node = (node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = head;
    head = new_node;
}

void printList()
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
     push(5);
     push(4);
     push(3);
     push(2);
     push(1);
     printf("Given linked list\n");
     printList();
     head->next->next->next->next->next = head->next;
     printf("\n%d", check_cycle());
     return 0;
}
