#include<stdio.h>

void enqueue(int a[], int *f, int *r, int val)
{
    if(*r == -1) (*f)++;
    a[++(*r)] = val;
}

int dequeue(int a[], int *f, int *r)
{
   return a[(*f)++];
}

void qA_to_qB(int q1[], int q2[], int *f1, int *r1, int*f2, int *r2)
{
    while(*f1 != *r1)
    {
        enqueue(q2,f2,r2,dequeue(q1,f1,r1));
    }
}

void print(int q1[], int f1, int r1)
{
    int temp = f1;
    while(temp <= r1)
    {
        printf("%d ", q1[temp++]);
    }
}

int main()
{
    int q1[100];
    int q2[100];
    int f1 = -1, r1 = -1;
    int f2 = -1, r2 = -1;
    int choice;
    int val;
    int index;
    do
    {
        printf("1.Push\n2.Pop\n3.Print\n4.Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Value ?:");
            scanf("%d", &val);
            enqueue(q1, &f1, &r1, val);
            printf("Successful!\n");
            break;
        case 2:
            qA_to_qB(q1, q2, &f1, &r1, &f2, &r2);
            int temp = dequeue(q1, &f1, &r1);
            printf("%d\n", temp);
            f1 = r1 = -1;
            qA_to_qB(q2, q1, &f2, &r2, &f1, &r1);
            enqueue(q1,&f1, &r1, dequeue(q2, &f2, &r2));
            f2 = r2 = -1;
            printf("Successful!\n");
            break;
        case 3:
            print(q1, f1, r1);
            printf("\n");
            break;
        case 4:
            break;
        }
        if(choice == 4) break;
    }while(5);
    return 0;
}
