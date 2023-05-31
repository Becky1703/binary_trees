#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function performs a let rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 *
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *pivot, *temp;
  
if (tree == NULL || tree->right == NULL)
return (NULL);

pivot = tree->right;
temp = pivot->left;

pivot->left = tree;
tree->right = temp;

if(temp != NULL)
temp->parent = tree;

if (tree->parent != NULL)
{
if (tree->parent->left == tree)
tree->parent->left = pivot;
else
tree->parent->right = pivot;
}
pivot->parent = tree->parent;
tree->parent = pivot;

return (pivot);
}
