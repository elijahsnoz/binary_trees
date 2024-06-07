#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *hight, *low;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	hight = first->parent, low = second->parent;
	if (first == low || !hight || (!hight->parent && low))
		return (binary_trees_ancestor(first, low));
	else if (hight == second || !low || (!low->parent && hight))
		return (binary_trees_ancestor(hight, second));
	return (binary_trees_ancestor(hight, low));
}