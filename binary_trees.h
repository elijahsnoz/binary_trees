#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Structures */
/* Structure for binary tree node */
typedef struct binary_tree_s
{
    int n; /* Node value */
    struct binary_tree_s *parent; /* Pointer to the parent node */
    struct binary_tree_s *left; /* Pointer to the left child node */
    struct binary_tree_s *right; /* Pointer to the right child node */
} binary_tree_t;

/* Structure for Binary Search Tree node */

typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t; /*AVL Tree*/


/* Function Prototypes */
/* Provided function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* Function prototypes */
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);
binary_tree_t *bst_insert(bst_t **tree, int value); /*Function prototype for bst_insert*/ 
bst_t *array_to_bst(int *array, size_t size);

/* Searches for a value in a binary search tree*/
bst_t *bst_search(const bst_t *tree, int value);

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/* function that checks if a binary tree is a valid AVL Tree*/
int binary_tree_is_avl(const binary_tree_t *tree);
size_t bst_height(const binary_tree_t *tree);
int is_avl_assis(const binary_tree_t *tree, int lo, int hi);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* New function to insert a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* New function to insert a node as the right-child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* New function to create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*a function that deletes an entire binary tree*/
void binary_tree_delete(binary_tree_t *tree);

/* Function that checks if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Function that checks if a given node is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* Function that goes through a binary tree using pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*  Function that goes through a binary tree using inorder traversal*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/*  Function that goes through a binary tree using postorder traversal*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* function that measures the depth of a node in a binary tree*/
size_t binary_tree_depth(const binary_tree_t *tree);

/*function that measures the size of a binary tree*/
size_t binary_tree_size(const binary_tree_t *tree);

/* function that counts the leaves in a binary tree*/
size_t binary_tree_leaves(const binary_tree_t *tree);

/*function that counts the nodes with at least 1 child in a binary tree*/
size_t binary_tree_nodes(const binary_tree_t *tree);

/* function that measures the height of a binary tree*/
size_t binary_tree_height(const binary_tree_t *tree);

/*function that measures the balance factor of a binary tree*/
int binary_tree_balance(const binary_tree_t *tree);


#endif /* BINARY_TREES_H */
