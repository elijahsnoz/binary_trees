#include <stdlib.h>
#include "binary_trees.h"

/*Helper function to calculate the height of the tree*/
int binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    int left_height = binary_tree_height(tree->left);
    int right_height = binary_tree_height(tree->right);

    // Return the greater height of the two subtrees plus one for the current node
    return (left_height > right_height ? left_height : right_height) + 1;
}

int binary_tree_balance(const binary_tree_t *tree)
{
    int left_height = 0;
    int right_height = 0;
    int balance;

    if (tree == NULL)
        return 0;
    if (tree->left != NULL)
    {
        left_height += 1;
        binary_tree_balance(tree->left);
    }
    if (tree->right != NULL)
    {
        right_height += 1;
        binary_tree_balance(tree->right);
    }
    balance = left_height - right_height;
    return balance;
}