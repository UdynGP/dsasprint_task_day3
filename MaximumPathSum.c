/*
Given a binary tree, find the maximum path sum from any node to any other node. The path must go through at least one node, and does not need to go through the root.
Input tree:-
         10
        /  \
       2   10
      / \    \
     20  1   -25
             /  \
            3    4
*/
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node.
struct TreeNode *newNode(int value)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Utility function to find the maximum of two integers.
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Recursive function to find the maximum path sum that goes through the given node.
int findMaxPathSumUtil(struct TreeNode *node, int *globalMax)
{
    if (node == NULL)
        return 0;

    // Recursive call on left child
    int left = max(findMaxPathSumUtil(node->left, globalMax), 0);

    // Recursive call on right child
    int right = max(findMaxPathSumUtil(node->right, globalMax), 0);

    // Update global maximum (considering the current node as the highest node of the path)
    *globalMax = max(*globalMax, node->val + left + right);

    // Return the maximum path sum where the current node is the highest node
    return node->val + max(left, right);
}

// Function to find the maximum path sum from any node to any other node in a binary tree.
int maxPathSum(struct TreeNode *root)
{
    int globalMax = INT_MIN;
    findMaxPathSumUtil(root, &globalMax);
    return globalMax;
}

// Main function to test the findMaxPathSum function.
int main()
{
    struct TreeNode *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("Maximum path sum is %d\n", maxPathSum(root));
    return 0;
}