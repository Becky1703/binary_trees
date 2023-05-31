#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - function to measure the depth of the binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: 0 if tree is NULL.
 *
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
