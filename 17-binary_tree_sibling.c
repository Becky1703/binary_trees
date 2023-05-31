#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: node
 *         if node or parent is NULL, return NULL
 *         if node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL || node->parent == NULL)
return (NULL);

if (node->parent->left == node)
return (node->parent->right);
return (node->parent->left);
}
