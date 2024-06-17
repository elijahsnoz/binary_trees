#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - Helper function to build AVL from sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the array segment
 * @end: Ending index of the array segment
 * @parent: Pointer to the parent node of the current subtree
 *
 * Return: Pointer to the root node of the created AVL subtree, or NULL on failure
 */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *root = (avl_t *)binary_tree_node((binary_tree_t *)parent, array[mid]);

    if (!root)
        return (NULL);

    root->left = sorted_array_to_avl_recursive(array, start, mid - 1, root);
    root->right = sorted_array_to_avl_recursive(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (sorted_array_to_avl_recursive(array, 0, size - 1, NULL));
}
