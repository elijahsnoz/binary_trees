#include <stdio.h>
#include "binary_trees.h"

/**
 * print_binary_tree - Helper function to print the binary tree
 * @tree: Pointer to the root node of the tree to print
 * @depth: Depth of the current node
 * @is_left: Flag to indicate if the node is a left child
 */
void print_binary_tree(const binary_tree_t *tree, int depth, int is_left)
{
    if (tree == NULL)
        return;

    print_binary_tree(tree->right, depth + 1, 0);

    for (int i = 0; i < depth; i++)
        printf("    ");
    
    if (is_left)
        printf("`-");
    else if (depth != 0)
        printf(".-");
    
    printf("(%03d)\n", tree->n);

    print_binary_tree(tree->left, depth + 1, 1);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    print_binary_tree(tree, 0, 0);
}
