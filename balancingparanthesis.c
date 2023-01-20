#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
struct stack
{
    char data;
    struct stack *next;
} *top = NULL, *head, *newnode, *temp;
typedef struct stack stack;
void push(char x)
{
    newnode = (stack *)malloc(sizeof(stack));
    newnode->data = x;
    newnode->next = NULL;
    if (!top)
    {
        top = newnode;
        head = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
void pop()
{
    if (top != NULL)
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
}
int count()
{
    if (top == NULL)
        return 0;
    else
        return 1;
}
void check(char val)
{
    if (val == '(' || val == '[' || val == '{')
        push(val);
    else if (val == ')' || val == ']' || val == '}')
        pop();
}
int main()
{
    char str[size];
    printf("Enter expression");
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        check(str[i]);
    if (!count())
        printf("Balanced paranthesis");
    else
        printf("Unbalanced paranthesis");
    return 0;
}
