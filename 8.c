#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;



node* head;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_list()
{
    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        swap(&(temp->data), &((temp->next)->data));
        temp = (temp->next)->next;
    }
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
     push(5);
     push(4);
     push(3);
     push(2);
     push(1);
     printf("Given linked list\n");
     printList();
     swap_list();
     printf("\nSwapped Linked list \n");
     printList();
     return 0;
}
