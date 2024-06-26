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

typedef binary_tree_t heap_t;
typedef binary_tree_t bst_t;  // Alias for binary tree node in BST context
typedef binary_tree_t avl_t;  // Alias for binary tree node in AVL context

/* Function Prototypes */
/* Provided function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* Function prototypes */
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size); // Prototype for array_to_heap

int binary_tree_is_bst(const binary_tree_t *tree);
binary_tree_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);

/* Searches for a value in a binary search tree */
bst_t *bst_search(const bst_t *tree, int value);

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/* Function that checks if a binary tree is a valid AVL Tree */
int binary_tree_is_avl(const binary_tree_t *tree);
size_t bst_height(const binary_tree_t *tree);
int is_avl_assis(const binary_tree_t *tree, int lo, int hi);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* New function to insert a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* New function to insert a node as the right-child of another node */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* New function to create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Function that deletes an entire binary tree */
void binary_tree_delete(binary_tree_t *tree);

/* Function that checks if a node is a leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Function that checks if a given node is a root */
int binary_tree_is_root(const binary_tree_t *node);

/* Function that goes through a binary tree using pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Function that goes through a binary tree using inorder traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Function that goes through a binary tree using postorder traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Function that measures the depth of a node in a binary tree */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Function that measures the size of a binary tree */
size_t binary_tree_size(const binary_tree_t *tree);

/* Function that counts the leaves in a binary tree */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Function that counts the nodes with at least 1 child in a binary tree */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Function that measures the height of a binary tree */
size_t binary_tree_height(const binary_tree_t *tree);

/* Function that measures the balance factor of a binary tree */
int binary_tree_balance(const binary_tree_t *tree);

int binary_tree_is_full(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);

binary_tree_t *binary_tree_sibling(binary_tree_t *node);

binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Function that goes through each level of a binary tree */
void binary_tree_level(const binary_tree_t *tree, void (*func)(int), size_t level);

/* Function that checks if a binary tree is a valid Max Binary Heap */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Helper functions for binary_tree_is_heap */
int is_complete_recursive(const binary_tree_t *tree, int index, int node_count);
int is_heap_recursive(const binary_tree_t *tree);

/* New function to insert a value in Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);

#endif /* BINARY_TREES_H */
