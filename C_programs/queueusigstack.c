#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int arr[100];
};

typedef struct stack *stack;

stack createStack(stack s)
{
    s->top = -1;
}

stack push(stack s, int val)
{
    s->top++;
    s->arr[s->top] = val;
    return s;
}

stack pop(stack s)
{
    s->top--;
    return s;
}

void printStack(stack s)
{
    for(int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

stack enqueue(stack s, stack s1, int val)
{
    while(s->top != -1)
    {
        s1 = push(s1, s->arr[s->top]);
        s = pop(s);
        printStack(s1);
    }
    s1 = push(s1, val);
    while(s1->top != -1)
    {
        s = push(s, s1->arr[s1->top]);
        s1 = pop(s1);
    }
    return s;
}

stack dequeue(stack s)
{
    s = pop(s);
    return s;
}

int main()
{
    stack s, s1;
    s = createStack(s);
    s1 = createStack(s1);
    s = push(s, 10);
    s = push(s, 12);
    s = push(s, 13);
    printStack(s);
    s = enqueue(s, s1, 9);
    printStack(s);
    s = dequeue(s);
    printStack(s);
    return 0;
}