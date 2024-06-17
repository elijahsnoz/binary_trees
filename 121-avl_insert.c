#include "binary_trees.h"
#include <stdlib.h>

/* Function prototypes for helper functions */
avl_t *create_node(avl_t *parent, int value);
int max(int a, int b);
int height(avl_t *node);
int balance_factor(avl_t *node);
avl_t *rotate_right(avl_t *y);
avl_t *rotate_left(avl_t *x);
avl_t *rebalance(avl_t *node);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, int value);

/**
 * avl_insert - Inserts a value into an AVL tree and ensures it remains balanced
 * @tree: Double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;
    return avl_insert_recursive(tree, NULL, value);
}

/**
 * avl_insert_recursive - Recursive helper function to insert a value in the AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @parent: Pointer to the parent node
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, int value)
{
    if (*tree == NULL)
    {
        *tree = create_node(parent, value);
        return *tree;
    }

    if (value < (*tree)->n)
        avl_insert_recursive(&((*tree)->left), *tree, value);
    else if (value > (*tree)->n)
        avl_insert_recursive(&((*tree)->right), *tree, value);
    else
        return NULL; /* Duplicate values are not allowed */

    /* Update the height of the current node */
    (*tree)->height = 1 + max(height((*tree)->left), height((*tree)->right));

    /* Rebalance the tree */
    *tree = rebalance(*tree);

    return *tree;
}

/**
 * create_node - Creates a new AVL tree node
 * @parent: Pointer to the parent node
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
    avl_t *new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1; /* New node is initially at leaf level */

    return new_node;
}

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of the two integers
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * height - Returns the height of a node
 * @node: Pointer to the node
 *
 * Return: The height of the node, or 0 if the node is NULL
 */
int height(avl_t *node)
{
    return (node == NULL) ? 0 : node->height;
}

/**
 * balance_factor - Computes the balance factor of a node
 * @node: Pointer to the node
 *
 * Return: The balance factor of the node
 */
int balance_factor(avl_t *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/**
 * rotate_right - Performs a right rotation on a subtree rooted with y
 * @y: Pointer to the root of the subtree to rotate
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    /* Perform rotation */
    x->right = y;
    y->left = T2;

    /* Update parents */
    if (T2 != NULL)
        T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    /* Update heights */
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/**
 * rotate_left - Performs a left rotation on a subtree rooted with x
 * @x: Pointer to the root of the subtree to rotate
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;

    /* Update parents */
    if (T2 != NULL)
        T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    /* Update heights */
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/**
 * rebalance - Rebalances a node if it becomes unbalanced
 * @node: Pointer to the node to rebalance
 *
 * Return: Pointer to the new root of the subtree
 */
avl_t *rebalance(avl_t *node)
{
    int balance = balance_factor(node);

    /* Left Left Case */
    if (balance > 1 && balance_factor(node->left) >= 0)
        return rotate_right(node);

    /* Left Right Case */
    if (balance > 1 && balance_factor(node->left) < 0)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    /* Right Right Case */
    if (balance < -1 && balance_factor(node->right) <= 0)
        return rotate_left(node);

    /* Right Left Case */
    if (balance < -1 && balance_factor(node->right) > 0)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}
