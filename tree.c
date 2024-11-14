#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL, *temp = NULL;
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}
struct Node *minimum(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int maximum(struct Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->key;
    }
}
struct Node *delete(struct Node *root, int key)
{
    if (!root)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = minimum(root->right);
            root->key = temp->key;
            root->right = delete (root->right, temp->key);
        }
    }
    return root;
}
int main()
{
    int ch, key;
    printf("\n1.Insert\n2.Search\n3.Minimum\n4.Maximum\n5.Inorder\
n6.Preorder\n7.Postorder\n8.Delete\n9.Exit\n");
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the key:");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the key:");
            scanf("%d", &key);
            temp = search(root, key);
            if (temp == NULL)
                printf("Key not found\n");
            else
                printf("Key found\n");
            break;
        case 3:
            struct Node *minNode = minimum(root);
            if (minNode != NULL)
                printf("Minimum key is %d\n", minNode->key);
            else
                printf("The tree is empty.\n");

            break;
        case 4:
            printf("Maximum key is %d\n", maximum(root));
            break;
        case 5:
            inorder(root);
            printf("\n");
            break;
        case 6:
            preorder(root);
            printf("\n");
            break;
        case 7:
            postorder(root);
            printf("\n");
            break;
        case 8:
            printf("Enter the key to delete:");
            scanf("%d", &key);
            delete (root, key);
            break;
        case 9:
            exit(0);
        }
    }
    return 0;
}