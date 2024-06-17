#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    int index = 0;
    int node_count = binary_tree_size(tree);
    return (is_complete_recursive(tree, index, node_count));
}

/**
 * is_complete_recursive - Helper function to check if tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: The index of the current node
 * @node_count: The total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int node_count)
{
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    return (is_complete_recursive(tree->left, 2 * index + 1, node_count) &&
            is_complete_recursive(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    if (!binary_tree_is_complete(tree))
        return (0);

    return (is_heap_recursive(tree));
}

/**
 * is_heap_recursive - Helper function to check if tree satisfies max heap property
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree satisfies max heap property, 0 otherwise
 */
int is_heap_recursive(const binary_tree_t *tree)
{
    if (!tree)
        return (1);

    if ((tree->left && tree->n < tree->left->n) ||
        (tree->right && tree->n < tree->right->n))
        return (0);

    return (is_heap_recursive(tree->left) && is_heap_recursive(tree->right));
}
