#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    // If the current node is a leaf node
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    // Recursively count leaves in the left and right subtrees
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
