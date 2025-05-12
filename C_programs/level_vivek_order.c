#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node* right;
    struct node* left;
};

struct node* q[100];
int l = 0;
int r = 0;

struct node* createNode(int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* createTree()
{
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    struct node* root = createTree();
    inorder(root);
    printf("\n");
    int arr[10];
    int i = 0;

    q[r++] = root;
    while(r - l != 0)
    {
        struct node* temp = q[l++];
        if(temp->right != NULL)
            q[r++] = temp->right;
        if(temp->left != NULL)
            q[r++] = temp->left;
        arr[i++] = temp->val;
    }

    printf("The answer is \n");
    for(int j = 6; j >= 0; j--)
    {
        printf("%d ", arr[j]);
    }
    return 0;
}