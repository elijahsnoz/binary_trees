#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes
 * @node1: The first node
 * @node2: The second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_up - Ensures the max-heap property from the inserted node upwards
 * @node: The node to start heapifying from
 *
 * Return: The node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
    return node;
}

/**
 * find_insertion_point - Performs level-order traversal to find the insertion point
 * @root: The root of the heap
 *
 * Return: The node where the new value should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
    heap_t *node = NULL;
    heap_t *queue[1024];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        node = queue[front++];
        if (!node->left || !node->right)
            break;
        queue[rear++] = node->left;
        queue[rear++] = node->right;
    }
    return node;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: The value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *insert_point;

    if (!root)
        return (NULL);

    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    insert_point = find_insertion_point(*root);

    new_node = binary_tree_node(insert_point, value);
    if (!new_node)
        return (NULL);

    if (!insert_point->left)
        insert_point->left = new_node;
    else
        insert_point->right = new_node;

    return heapify_up(new_node);
}
