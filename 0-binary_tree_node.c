#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: points to the parent of the nod to create
 * @value: the value of the new node
 *
 * Return: NULL if it fails
 *         A pointer to the new node otherwise
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newNode;

newNode = malloc(sizeof(binary_tree_t));
if (newNode == NULL)
return (NULL);

newNode->n = value;
newNode->parent = parent;
newNode->left = NULL;
newNode->right = NULL;

return (newNode);
}
