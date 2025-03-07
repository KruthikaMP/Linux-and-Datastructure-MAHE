#include <stdio.h>
#include <stdlib.h>
 
// A binary tree node has data, pointer to left child
// and a pointer to right child
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
 
// Helper function that allocates a new node with the
// given data and NULL left and right pointers.
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
 
// Function to check if two trees have same
// structure
int isSameStructure(Node* a, Node* b)
{
    // 1. both empty
    if (a == NULL && b == NULL)
        return 1;
    // 2. both non-empty -> compare them
    if (a != NULL && b != NULL) {
        return (isSameStructure(a->left, b->left)
                && isSameStructure(a->right, b->right));
    }
    // 3. one empty, one not -> false
    return 0;
}
 
// Driver code
int main()
{
    Node* root1 = newNode(10);
    Node* root2 = newNode(100);
    root1->left = newNode(7);
    root1->right = newNode(15);
    root1->left->left = newNode(4);
    root1->left->right = newNode(9);
    root1->right->right = newNode(20);
 
    root2->left = newNode(70);
    root2->right = newNode(150);
    root2->left->left = newNode(40);
    root2->left->right = newNode(90);
    root2->right->right = newNode(200);
 
    if (isSameStructure(root1, root2))
        printf("Both trees have same structure");
    else
        printf("Trees do not have same structure");
    return 0;
}