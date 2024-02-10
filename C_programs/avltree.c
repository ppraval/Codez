#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
    int height;
};

typedef struct node* node;

node createNode(int val)
{  
    node new_node = (node)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

node insertBST(node root, int val)
{
    node new_node = createNode(val);
    if(root == NULL)
    {
        return new_node;
    }
    if(root->val > val)
        root->left = insertBST(root->left, val);
    if(root->val < val)
        root->right = insertBST(root->right, val);
    return root;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int height(node tree_node)
{
    if(tree_node == NULL)
        return 0;
    return tree_node->height;
}

void inorderTraversal(node root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

void preorderTraversal(node root)
{
    if(root == NULL)
        return;
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


node leftRotate(node x)
{
    node y = x->right;
    node T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

node rightRotate(node y)
{
    node x = y->left;
    node T2 = x->right;

    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

int getBalance(node tree_node)
{
    if(tree_node == NULL)
        return 0;
    return height(tree_node->left) - height(tree_node->right);
}

node insertAVL(node root, int val)
{
    node new_node = createNode(val);
    if(root == NULL)
    {
        return new_node;
    }
    if(root->val > val)
        root->left = insertAVL(root->left, val);
    else if(root->val < val)
        root->right = insertAVL(root->right, val);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance_factor = getBalance(root);

    if(balance_factor > 1 && val < root->left->val)
        return rightRotate(root);
    if(balance_factor < -1 && val > root->right->val)
        return leftRotate(root);
    if(balance_factor > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance_factor < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

node makeASampleTree()
{
    node root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 2);
    root = insertBST(root, 3);
    root = insertBST(root, 1);
    root = insertBST(root, 4);
    root = insertBST(root, 7);
    root = insertBST(root, 6);
    root = insertBST(root, 9);
    return root;
}

int main()
{
    // node root = makeASampleTree();
    node root = NULL;
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 30);
    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    root = insertAVL(root, 25);
    printf("The inorder traversal is: ");
    inorderTraversal(root);
    printf("\n");
    printf("The preorder traversal is: ");
    preorderTraversal(root);
    return 0;
}
