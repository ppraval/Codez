#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node* right;
    struct node* left;
};

typedef struct node *node;

node createNode(int key)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

void infixTraversal(node root)
{
    if (root == NULL)
    {
        return;
    }
    infixTraversal(root->left);
    printf("%d ", root->key);
    infixTraversal(root->right);
}

void postfixTraversal(node root)
{
    if (root == NULL)
    {
        return;
    }
    postfixTraversal(root->left);
    postfixTraversal(root->right);
    printf("%d ", root->key);
}

void prefixTraversal(node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->key);
    prefixTraversal(root->left);
    prefixTraversal(root->right);
}

node arrayToTree(node root, int arr[], int  i, int n)
{
    if (i < n)
    {
        node temp = createNode(arr[i]);
        root = temp;
        root->left = arrayToTree(root->left, arr, 2 * i + 1, n);
        root->right = arrayToTree(root->right, arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    node root = NULL;
    root = arrayToTree(root, arr, 0, n);
    printf("The infix traversal is this : ");
    infixTraversal(root);
    printf("\n");
    printf("The prefix traversal is this : ");
    prefixTraversal(root);
    printf("\n");
    printf("The postfix traversal is this : ");
    postfixTraversal(root);
    printf("\n");
    return 0;
}