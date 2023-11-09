#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char arr[1000];
};

typedef struct stack *stack;

stack createStack(int size)
{
    stack s = (stack)malloc(sizeof(stack));
    s->size = size;
    s->top = -1;
    return s;
}

stack push(stack s, char data)
{
    s->top++;
    s->arr[s->top] = data;
    return s;
}

char pop(stack s)
{
    char ch = s->arr[s->top];
    s->top--;
    return ch;
}

int isOperator(char ch)
{
    if( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return -1;
    }
}

void printStack(stack s)
{
    for(int i = 0; i < s->top; i++)
    {
        printf("%c ", s->arr[i]);
    }
    printf("\n");
}

void infixToPostfix(stack s, char infix[], char postfix[], int n)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(infix[i] == '(')
        {
            s = push(s, '(');
            printStack(s);
        }
        else if(infix[i] == ')')
        {
            while(1)
            {
                char ch = pop(s);
                if(ch == '(')
                {
                    break;
                }
                else
                {
                    postfix[j++] = ch;
                }
            }
        }
        else
        {
            if(isOperator(infix[i]) == 0)
            {
                postfix[j++] = infix[i];
            }
            else
            {
                if(s->top == -1)
                {
                    s = push(s, infix[i]);
                }
                else
                {
                    while(s->top > -1)
                    {
                        if(precedence(infix[i]) <= precedence(s->arr[s->top]))
                        {
                            postfix[j++] = pop(s);
                            s = push(s, infix[i]);
                            break;
                        }
                        else
                        {
                            s = push(s, infix[i]);
                            break;
                        }
                    }
                }
            }
        }
    }
    while(s->top > -1)
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}


int main()
{
    int n = 7;
    char postfix[100];
    char infix[] = {'(', '1', '+', '3', ')', '*', '2'};
    // puts(infix);
    // printf("\n");

    // scanf("%d", &n);
    stack s = createStack(n);
    // for(int i = 0; i < n; i++)
    // {
    //     if(i == 0)
    //     {
    //         scanf("\n%c", &infix[i]);
    //     }
    //     else
    //     {
    //         scanf(" %c", &infix[i]);
    //     }
    // }
    infixToPostfix(s, infix, postfix, n);
    printf("Done with the process only have to print now\n");
    for(int i = 0; i < strlen(postfix); i++)
    {
        if(i == 0)
        {
            printf("%c", postfix[i]);
        }
        else
        {
            printf(" %c", postfix[i]);
        }
    }
    return 1;
}