#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - function that goes through a binary tree
 * using inorder traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter
 * Return: Always 0(success).
 *        if tree or func is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

/* traverse the left subtree */
binary_tree_postorder(tree->left, func);

/* traverse the right subtree */
binary_tree_postorder(tree->right, func);

/* call the function for current node */
func(tree->n);
}
