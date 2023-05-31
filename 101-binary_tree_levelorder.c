#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

queue_node_t *create_queue_node(struct binary_tree_s *node);
void enqueue(queue_t *queue, struct binary_tree_s *node);
struct binary_tree_s *dequeue(queue_t *queue);
int is_empty(queue_t *queue);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_queue_node - function creates a new queue node and
 * assigns the given ninary tree node to it
 *
 * @node: pointer to node to create
 *
 * Return: new node.
 */
queue_node_t *create_queue_node(struct binary_tree_s *node)
{
queue_node_t *new_node;
new_node = malloc(sizeof(queue_node_t));
if (new_node == NULL)
{
fprintf(stderr, "Failed to allocate memory for queue node.\n");
exit(EXIT_FAILURE);
}
new_node->node = node;
new_node->next = NULL;
return (new_node);
}

/**
 * enqueue - function adds a binary tree node to the rear of the queue
 *           and creates a new queue node using create queue function
 * @queue: pointer to the queue of the node
 * @node: pointer to node
 *
 * Return: Always 0 (success)
 */
void enqueue(queue_t *queue, struct binary_tree_s *node)
{
queue_node_t *new_node;
new_node  = create_queue_node(node);
if (queue->rear == NULL)
{
queue->front = queue->rear = new_node;
}
else
{
queue->rear->next = new_node;
queue->rear = new_node;
}
}

/**
 * dequeue - function removes and returns the binary tree node from the front
 *           of the queue
 * @queue: pointer to the queue of the node
 *
 * Return: NULL if an error occurs, or pointer to the new node otherwise
 *
 */
struct binary_tree_s *dequeue(queue_t *queue)
{
if (queue->front == NULL)
return (NULL);

queue_node_t *front;
front = queue->front;

struct binary_tree_s *node;
node = front->node;

queue->front = queue->front->next;
if (queue->front == NULL)
queue->rear = NULL;

free(front);
return (node);
}

/**
 * is_empty - checks if queue is empty
 * @queue: pointer to queue
 * Return: null.
 */
int is_empty(queue_t *queue)
{
return (queue->front == NULL);
}

/**
 * binary_tree_levelorder - function goes through a binary tree using
 * leveorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *        The value in the node will be passed as a parameter
 *        to this function
 * Return: if tree or func is NULL, does nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return; /* If tree or func is NULL, do nothing */
queue_t queue;
queue.front = queue.rear = NULL;

enqueue(&queue, (struct binary_tree_s *)tree);

while (!is_empty(&queue))
{
binary_tree_t *node;
node = dequeue(&queue);
func(node->n);

if (node->left != NULL)
enqueue(&queue, node->left);

if (node->right != NULL)
enqueue(&queue, node->right);
}
}
