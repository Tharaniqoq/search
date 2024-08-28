#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search for a specific value in the binary tree
bool searchTree(TreeNode* root, int target) {
    // Base case: if the tree is empty or the target is found
    if (root == NULL) {
        return false;
    }
    if (root->value == target) {
        return true;
    }

    // Recursively search in the left and right subtrees
    return searchTree(root->left, target) || searchTree(root->right, target);
}

// Main function to demonstrate the search
int main() {
    // Create a simple binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Define the target value to search for
    int target = 4;

    // Perform search
    if (searchTree(root, target)) {
        printf("Value %d found in the tree.\n", target);
    } else {
        printf("Value %d not found in the tree.\n", target);
    }

    // Free allocated memory (not shown here for simplicity)
    // Implement proper cleanup in real code

    return 0;
}
