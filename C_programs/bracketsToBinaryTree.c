#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int key;
    struct node* right;
    struct node* left;
};

typedef struct node *node;

struct valIndex
{
    int val;
    int index;
};

typedef struct valIndex *vivek;

node createNode(int key)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

vivek bracketToBT(node root, char arr[], int i)
{
    int val = 0;
    int j;
    vivek vivek1 = (vivek)malloc(sizeof(struct valIndex));
    vivek vivek_temp;

    for(j = i + 1; j < strlen(arr); j++)
    {
        if(arr[j] == ' ')
            continue;
        if(arr[j] == '(' || arr[j] == ')')
            break;
        val = (val * 10) + (arr[j] - '0');
    }

    if(arr[j] == ')' || j >= strlen(arr))
    {
        vivek1->val = val;
        vivek1->index = j + 1;
        return vivek1;
    }

    root->key = val;
    root->left = createNode(0);
    vivek left = bracketToBT(root->left, arr, j + 1);
    root->right = createNode(0);
    vivek right = bracketToBT(root->right, arr, left->index + 1);

    vivek1->index = right->index + 2;
    vivek1->val = val;
    
    return vivek1;
}

void inorderTraversal(node root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    if(root->key != 0)
        printf("%d ", root->key);
    inorderTraversal(root->right);
}

int main()
{
    char string[] = "( 50 ( 3 ( 8 ( ) ( ) ) ( 4 ( ) ( ) ) ) ( 6 ( ) ( ) ) )";
    int i = 0;
    node root = createNode(0);
    vivek v1 = bracketToBT(root, string, i);
    inorderTraversal(root);
    return 1;
}