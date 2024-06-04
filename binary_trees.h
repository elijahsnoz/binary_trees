#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Libraries */
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

/* Function Prototypes */
/* Provided function to print binary tree */
void binary_tree_print(const binary_tree_t *);

/* New function to insert a node as the left-child of another node */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* New function to create a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif /* BINARY_TREES_H */
