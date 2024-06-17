#include "binary_trees.h"

/**
 * bst_min_value_node - Finds the node with the smallest value
 * @node: Pointer to the root node of the tree to search
 *
 * Return: Pointer to the node with the smallest value
 */
avl_t *bst_min_value_node(avl_t *node)
{
    avl_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return (current);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after deletion
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return (root);

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            avl_t *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            avl_t *temp = bst_min_value_node(root->right);
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return (root);

    root->height = 1 + binary_tree_height(root->left) + binary_tree_height(root->right);

    int balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return (binary_tree_rotate_right(root));

    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }

    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return (binary_tree_rotate_left(root));

    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
    }

    return (root);
}
