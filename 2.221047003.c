#include <stdio.h>
#include <stdlib.h>
 
 
// BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
// Utility function to create a new Node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
// Function to perform inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL)
        return;
 
    inorder(root->left);
 
    printf("%d " ,root->data);
 
    inorder(root->right);
}
 
// Function to check if two BSTs
// are identical
int isIdentical(struct Node* root1,struct Node* root2)
{
    // Check if both the trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (root1 == NULL || root2 == NULL)
        return 0;
    else { // Check if current data of both trees equal
        // and recursively check for left and right subtrees
        if (root1->data == root2->data && isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right))
            return 1;
        else
            return 0;
    }
}
 
// Driver code
int main()
{
    struct Node* root1 = newNode(5);
    struct Node* root2 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(8);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
 
    root2->left = newNode(3);
    root2->right = newNode(8);
    root2->left->left = newNode(2);
    root2->left->right = newNode(4);
 
    if (isIdentical(root1, root2))
        printf( "Both BSTs are identical");
    else
        printf("BSTs are not identical") ;
 
    return 0;
}