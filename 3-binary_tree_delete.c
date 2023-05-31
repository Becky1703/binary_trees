#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - function to delete a binary tree
 * @tree: A pointer to the root of the node of the tree to be deleted
 *
 * Return: Always 0 success.
 *
 */
void binary_tree_delete(binary_tree_t *tree)
{

if (tree == NULL)
{
return;
}
binary_tree_delete(tree->left);
binary_tree_delete(tree->right);
free(tree);

}
