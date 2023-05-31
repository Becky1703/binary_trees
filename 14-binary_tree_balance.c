#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance factor of a
 * binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: if tree is NULL, function returns 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
{
if (tree == NULL)
return (0);
}

int left_height = binary_tree_height(tree->left);
int right_height = binary_tree_height(tree->right);

return (left_height - right_height);

}

/**
 * binary_tree_height - function to measure the height of the binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: 0 if tree is NULL.
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
{
size_t l = 0, r = 0;

l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
r = tree->right ? 1 + binary_tree_height(tree->right) : 1;

return ((l > r) ? l : r);
}
}
