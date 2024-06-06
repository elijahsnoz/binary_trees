#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * print_tree - Recursive helper function to print a binary tree.
 * @tree: Pointer to the root node of the tree to print.
 * @depth: The current depth in the tree.
 * @is_left: Whether the current node is a left child.
 */
void print_tree(const binary_tree_t *tree, int depth, int is_left)
{
    if (tree == NULL)
        return;

    if (tree->right != NULL)
        print_tree(tree->right, depth + 1, 0);

    for (int i = 0; i < depth; i++)
        printf("       ");

    if (is_left)
        printf("`--");
    else if (depth != 0)
        printf(".--");

    printf("(%03d)\n", tree->n);

    if (tree->left != NULL)
        print_tree(tree->left, depth + 1, 1);
}

/**
 * binary_tree_print - Prints a binary tree.
 * @tree: Pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    if (tree->left == NULL && tree->right == NULL)
    {
        printf("(%03d)\n", tree->n);
        return;
    }

    printf("       .-------(%03d)-------.\n", tree->n);
    if (tree->left)
        print_tree(tree->left, 1, 1);
    else
        printf("  .--(nil)\n");

    if (tree->right)
        print_tree(tree->right, 1, 0);
    else
        printf("  `--(nil)\n");
}
