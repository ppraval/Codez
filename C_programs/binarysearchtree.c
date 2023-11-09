#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node* right;
    struct node* left;
    struct node* parent;
};

typedef struct node *node;

node createNode(int key)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->parent = NULL;
    return new_node;
}

node insertNode(node root, int key)
{
    node new_node = createNode(key);
    if(root == NULL)
    {
        return new_node;
    }
    if(key < root->key)
    {
        root->left = insertNode(root->left, key);
        root->left->parent = root;
    }
    if(key > root->key)
    {
        root->right = insertNode(root->right, key);
        root->right->parent = root;
    }
    return root;
}

void infixTraversal(node root)
{
    if(root == NULL)
    {
        return;
    }
    infixTraversal(root->left);
    printf("%d ", root->key);
    infixTraversal(root->right);
}

node searchNode(node root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (root->key > key)
    {
        return searchNode(root->left, key);
    }
    else if (root->key < key)
    {
        return searchNode(root->right, key);
    }    
}

node minNode(node root)
{
    node traverse_node = root;
    while(traverse_node->left != NULL)
    {
        traverse_node = traverse_node->left;
    }
    return traverse_node;
}

node maxNode(node root)
{
    node traverse_node = root;
    while(traverse_node-?right != NULL)
    {
        traverse_node = traverse_node->right;
    }
    return traverse_node;
}

node successorNode(node root, int key)
{
    node temp = searchNode(root, key);
    if (temp->right != NULL)
    {
        node new_node = minNode(temp->right);
        return new_node;
    }
    else
    {
        node parent = temp->parent;
        while(parent != NULL && temp == parent->left)
        {
            temp = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

node predessorNode(node root, int key)
{
    node temp = searchNode(root, key);
    if (temp->left != NULL)
    {
        node new_node = maxNode(temp->left);
        return new_node;
    }
    else
    {
        node parent = temp->parent;
        while(parent != NULL && temp == parent->left)
        {
            temp = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

node deleteNode(node root, int key)
{
    node temp = searchNode(root, key);
    if(temp->right == NULL && temp->left == NULL)
    {
        if(temp == temp->parent->right)
        {
            temp->parent->right = NULL;
            return root;
        }
        else if (temp == temp->parent->left)
        {
            temp->parent->left = NULL;
            return root;
        }
    }
    if(temp->left == NULL)
    {
        temp->key = temp->right->key;
        temp->right = NULL;
        return root;
    }
    if(temp->right == NULL)
    {
        temp->key = temp->left->key;
        temp->left = NULL;
        return root;
    }
    if(temp->right != NULL && temp->left != NULL)
    {
        node new_temp = successorNode(root, key);
        int temp_key = new_temp->key;
        root = deleteNode(root, new_temp->key);
        temp->key = temp_key;
        return root;
    }
}

int main()
{
    node root = NULL;
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 0);
    root = insertNode(root, 7);
    infixTraversal(root);
    printf("\n");
    node search = searchNode(root, 1);
    if (search == NULL)
    {
        printf("Boooooooo\n");
    }
    else
    {
        printf("YAY we found it!!!\n");
    }
    root = deleteNode(root, 1);
    infixTraversal(root);
    printf("\n");
    return 0;
}