#include<stdio.h>

void push(int a[],int *top, int n)
{
    a[++(*top)] = n;
}
int pop(int a[], int *top)
{
    return a[(*top)--];
}

int is_empty(int a[], int top)
{
    return (top==-1);
}

void enqueue(int inbox[], int *top1, int val)
{
    push(inbox, top1, val);
}

void inbox_to_outbox(int inbox[], int outbox[], int *top1, int *top2)
{
    while(!is_empty(inbox, *top1))
    {
        push(outbox,top2,pop(inbox,top1));
    }
}

void print(int inbox[], int outbox[], int *top1, int *top2)
{
    if(is_empty(outbox, *top2))
    {
        inbox_to_outbox(inbox, outbox, top1, top2);
    }
    int temp = 0;
    while(temp <= *top2)
    {
        printf("%d ", outbox[temp++]);
    }
}

int main()
{
    int inbox[100];
    int outbox[100];
    int top1 = -1;
    int top2 = -1;
    int choice;
    int val;
    int index;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Print\n4.Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Value ?:");
            scanf("%d", &val);
            enqueue(inbox, &top1, val);
            break;
        case 2:
            if(is_empty(outbox, top2))
            {
                inbox_to_outbox(inbox, outbox, &top1, &top2);
            }
            pop(outbox, &top2);
            printf("Successful!\n");
            break;
        case 3:
            print(inbox, outbox, &top1, &top2);
            printf("\n");
            break;
        case 4:
            break;
        }
        if(choice == 4) break;
    }
    while(5);
    return 0;
}
