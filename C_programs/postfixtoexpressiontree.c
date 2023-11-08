#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

typedef struct node *node;

struct stack 
{
    int top;
    node arr[100];
};

typedef struct stack *stack;

node createNode(char data, node left, node right) 
{
    node temp;
    temp = (node)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = left;
    temp->right = right;
    return temp;
}

stack createStack(stack s)
{
    s->top = -1;
    return s;
}

stack push(stack s, node n)
{

    s->top++;
    s->arr[s->top] = n;
 
    return s;
}

node pop (stack s)
{
    node temp;
    if (s->top == -1)
    {
        printf("-1\n");
    }
    else
    {
        temp = s->arr[s->top];
        s->top--;
    }
    return temp;
}

void printStack(stack s)
{
    if(s->top == -1)
    {
        printf("-1\n");
    }
    else
    {
        for(int i = 0; i <= s->top; i++)
        {
            printf("%s", s->arr[i]);
        }
    }
}

int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

node postfixToExpTree(stack s, char postfix[])
{
    for(int i = 0; i < 15; i++) 
    {
        if(isOperator(postfix[i]) == 0)
        {
            node temp = createNode(postfix[i], NULL, NULL);
            printf("the node data is %c\n", temp->data);
            s = push(s, temp);
        }
        else
        {
            node left = pop(s);
            node right = pop(s);
            node new_temp = createNode(postfix[i], left, right);
            printf("the node data is %c\n", new_temp->data);
            printf("Right data is %c Left data %c\n", new_temp->right->data, new_temp->left->data);
            s = push(s, new_temp);
        }
    }
    node final_tree = pop(s);
    return final_tree;
}

int heightExpTree(node root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = heightExpTree(root->left);
        int right_height = heightExpTree(root->right);
        if(left_height >= right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}
int minDistanceExpTree(node root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = heightExpTree(root->left);
        int right_height = heightExpTree(root->right);
        if(left_height <= right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

int main()
{
    // char exp[] = {'2', '3', '-', '4', '0', '/', '*'};
    char exp[] = {'1', '2', '/', '3', '4', '-', '*', '6', '7', '*', '+', '8', '5', '/', '*'};
    stack s = createStack(s);
    printf("the string length is %d\n", strlen(exp));
    node root = postfixToExpTree(s, exp);
    printf("the root tree is %c\n", root->data);
    printf("the height of the root is %d\n", heightExpTree(root) - 1);
    printf("The min distance from leave to root is %d\n", minDistanceExpTree(root) - 1);
    return 1;
}