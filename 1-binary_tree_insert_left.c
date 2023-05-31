#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as left child of another node.
 * @parent: pointer to the node to insert the lef child in.
 * @value: value to store in the new node.
 *
 * Return: pointer to created node or NULL if it fails or if
 *         parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *newNode;

if (parent == NULL)
return (NULL);

newNode = binary_tree_node(parent, value);
if (newNode == NULL)
return (NULL);

if (parent->left != NULL)
{
newNode->left = parent->left;
parent->left->parent = newNode;
}
parent->left = newNode;

return (newNode);
}
