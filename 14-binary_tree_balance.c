#include <stdlib.h>
#include "binary_trees.h"

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