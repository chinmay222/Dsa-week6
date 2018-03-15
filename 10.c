#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

node* head;
node* tail;

void getJosephusPosition(int m, int n)
{
    node *ptr1 = head->next, *ptr2 = head->next;  //1 is gone already
    while (ptr1->next != ptr1)
    {
        // Find m-th node
        int count = 1;
        while (count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        /* Remove the m-th node */
        ptr2->next = ptr1->next;
        ptr1 = ptr2->next;
    }
    printf ("Last person left standing is %d\n ", ptr1->data);
}

void push(int new_data)
{
    node* new_node = (node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = head;
    head = new_node;
    if(tail == NULL) tail = new_node;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i = n;
    while(i>=1)
    {
        push(i);
        i--;
    }
    tail->next = head->next;   //removing 1 here itself
    getJosephusPosition(m, n);
    return 0;
}
