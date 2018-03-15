#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a;
    struct node* next;
    struct node* prev;
}node;

node *head;
node *tail;

void insert_at_end(int val)
{
    if(head == NULL)
    {
        node *p = (node *)malloc(sizeof(node));
        p->a = val;
        p->next = NULL;
        p->prev = NULL;
        head = p;
        tail = p;
    }
    else
    {
        node *p = (node *)malloc(sizeof(node));
        p->a = val;
        p->next = NULL;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
    printf("Done\n");
}

void insert_at_beginning(int val)
{
    if(head == NULL)
    {
        node *p = (node *)malloc(sizeof(node));
        p->a = val;
        p->next = NULL;
        p->prev = NULL;
        head = p;
        tail = p;
    }
    else
    {
        node *p = (node *)malloc(sizeof(node));
        p->a = val;
        p->next = head;
        p->prev = NULL;
        head->prev = p;
        head = p;
    }
    printf("Done\n");
}

void remove_index(int index)
{
    node *cur = head;
    int counter = 1;
    while(counter != index)
    {
        cur = cur->next;
        counter++;
    }
    if(cur == head)
    {
        head = head-> next;
        head->prev = NULL;
    }
    else if(cur == tail)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        (cur->prev)->next = cur->next;
        (cur->next)->prev = cur->prev;
    }
    printf("Done\n");
}

void remove_first()
{
    head = head-> next;
    head->prev = NULL;
    printf("Done\n");
}

void remove_last()
{
    tail = tail->prev;
    tail->next = NULL;
    printf("Done\n");
}

void print()
{
    node *cur = head;
    while(cur != NULL)
    {
        printf("%d\n", cur->a);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    int val;
    int index;
    do
    {
        printf("1.Insert at beginning\n2.Insert at end\n3.Remove at ith place\n4.Remove first\n5.Remove last\n6.Print\n7.Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Value ?:");
                    scanf("%d", &val);
                    insert_at_beginning(val);
                    break;
            case 2: printf("Value ?:");
                    scanf("%d", &val);
                    insert_at_end(val);
                    break;
            case 3: printf("Index ?:");
                    scanf("%d", &index);
                    remove_index(index);
                    break;
            case 4: remove_first();
                    break;
            case 5: remove_last();
                    break;
            case 6: print();
                    break;
            case 7: break;
        }
        if(choice == 7) break;
    }while(5);

    return 0;
}
