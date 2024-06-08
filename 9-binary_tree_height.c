#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height
 * Return: height of the tree and  0 if is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	/*
	 * Return the greater height of the two subtrees
	 * plus one for the current node
	 */
	return (left_height > right_height ? left_height : right_height);
}
