#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

node* head;

void reverse()
{
    node* prev   = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
     node* head = NULL;
     push(20);
     push(4);
     push(15);
     push(85);
     printf("Given linked list\n");
     printList();
     reverse();
     printf("\nReversed Linked list \n");
     printList();
     return 0;
}
