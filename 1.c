#include<stdio.h>

int stack[100];
int tp = -1;

void push(int n)
{
    stack[++tp] = n;
}
void pop()
{
    tp--;
}
int top()
{
    return stack[tp];
}

int is_empty()
{
    return (tp==-1);
}

int getMaxArea(int hist[], int n)
{
    int max_area = 0;
    int area_with_top;
    int top_value;
    int i = 0;
    while (i < n)
    {
        if (is_empty() || hist[top()] <= hist[i])
        {
            push(i++);
        }
        else
        {
            top_value = top();
            pop();
            area_with_top = hist[top_value] * (is_empty() ? i : i - top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (is_empty() == 0)
    {
        top_value = top();
        pop();
        area_with_top = hist[top_value] * (is_empty() ? i : i - top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main()
{
    int n;
    scanf("%d", &n);
    int hist[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &hist[i]);
    }
    printf("%d", getMaxArea(hist, n));
    return 0;
}
