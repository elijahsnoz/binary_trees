#include "binary_trees.h"

int count_nodes(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, int index, int node_count);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    int node_count = 0;
    int index = 0;
    node_count = count_nodes(tree);
    return (is_complete(tree, index, node_count));
}

/**
 * count_nodes - Counts the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Checks if the binary tree is complete using node count
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
    if (!tree)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete(tree->left, 2 * index + 1, node_count) &&
            is_complete(tree->right, 2 * index + 2, node_count));
}
