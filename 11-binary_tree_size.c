#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	/*
	 * Size of the current node is 1 + size
	 * of left subtree + size of right subtree
	 */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
