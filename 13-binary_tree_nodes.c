#include <stdlib.h>
#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t count = 0;

    if (tree == NULL)
        return 0;

    // Check if the current node has at least one child
    if (tree->left != NULL || tree->right != NULL)
        count = 1;
    count += binary_tree_nodes(tree->left);
    count += binary_tree_nodes(tree->right);
    
    return count;
}