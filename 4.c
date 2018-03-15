#include<stdio.h>

#define MAX 50
char infixToPostfixStack[MAX];   //this is the stack we will use to hold intermediate operators during conversion from infix to postfix
int top1 = -1;                   // to traverse the infixToPostfixStack
char infix[MAX];                 //the given infix expression
char postfix[MAX];               //the final postfix expression
int evaluationStack[MAX];
int top2 = -1;

int precedence(char c)
{
    // This function returns the precedence of each operator we encounter from highest i.e. 5 to lowest i.e. 1
    switch(c)
    {
        case '/':
        case '*': return 3;
        case '-':
        case '+': return 2;
        case '(': return 1;
    }

}

void infixToPostfixPush(char c)
{
    // This function pushes elements into the stack for Task 1
    top1++;
    infixToPostfixStack[top1]=c;
}

void evaluationPush(int n)
{
    top2++;
    evaluationStack[top2]=n;
}

char infixToPostfixPop()
{
    // This function pops elements from the top of the stack for Task 1
    char c = infixToPostfixStack[top1];
    top1--;
    return c;
}

int is_infixToPostfix_empty()
{
    return (top1==-1);
}

int evaluationPop()
{
    int c = evaluationStack[top2];
    top2--;
    return c;
}

void infixToPostfix()
{
    // This function converts the given infix expression to postfix
    char element;
    int i=0,k=0;                 //indices of infix, postfix respectively
    scanf("%s", infix);
    element = infix[i];
    while(element!='\0')
    {
        if(element=='(')
        {
            infixToPostfixPush(element);
        }
        else if(isalnum(element)!=0)       //To check whether element is an operand
        {
            postfix[k] = element;
            k++;
        }
        else if(element==')')
        {
            while((! is_infixToPostfix_empty()) && (infixToPostfixStack[top1]!='('))
            {
                postfix[k] = infixToPostfixPop();
                k++;
            }
            infixToPostfixPop();                   //to get rid of the remaining '('
        }
        else                                        // if element is an operator..
        {
            while((! is_infixToPostfix_empty()) && (precedence(infixToPostfixStack[top1])>=precedence(element)))
            {
                postfix[k] = infixToPostfixPop();
                k++;
            }
            infixToPostfixPush(element);
        }
        i++;
        element = infix[i];
    }
    while (! is_infixToPostfix_empty())
        postfix[k++] = infixToPostfixPop();
    postfix[k] = '\0';
    printf("%s", postfix);
}

int evaluate()
{
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(postfix[i]))
            evaluationPush(postfix[i] - '0');

        //  If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else
        {
            int val1 = evaluationPop();
            int val2 = evaluationPop();
            switch (postfix[i])
            {
             case '+': evaluationPush(val2 + val1); break;
             case '-': evaluationPush(val2 - val1); break;
             case '*': evaluationPush(val2 * val1); break;
             case '/': evaluationPush(val2/val1);   break;
            }
        }
    }
    return evaluationPop();
}

int main()
{
    infixToPostfix();
    printf("\n%d",evaluate());
}
