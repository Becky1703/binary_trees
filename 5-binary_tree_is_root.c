#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - function to check if node is a root
 * @node: pointer to the node to check
 *
 * Return: 1 if node ia root, 0 otherwise.
 *         if node is NULL, return 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);

if (node->parent == NULL)
return (1);
else
return (0);
}
