#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	/*
	 * If tree is NULL, return 0
	 */
	if (tree == NULL)
		return (0);
	/*
	 * If the node is a leaf,
	 * return 1
	 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/*
	 * If the node has two children,
	 * check recursively
	 */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	/*
	 * If the node has only one child, return 0
	 */
	return (0);
}
