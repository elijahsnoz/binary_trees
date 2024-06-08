#include <stdlib.h>
#include "binary_trees.h"

/* Helper function to calculate the height of the tree */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Return the greater height of the two subtrees plus one for the current node
    return (left_height > right_height ? left_height : right_height) + 1;
}

int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    int left_height = (tree->left) ? (int)binary_tree_height(tree->left) : -1;
    int right_height = (tree->right) ? (int)binary_tree_height(tree->right) : -1;

    return left_height - right_height;
}
