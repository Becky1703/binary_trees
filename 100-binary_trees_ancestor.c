#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that finds the lowest
 * common ancestor of two nodes.
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 *         if no common ancestor was found, function returns NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
binary_tree_t *mum, *dad;

if (!first || !second)
return (NULL);
if (first == second)
return ((binary_tree_t *)first);

mum = first->parent, dad = second->parent;
if (first == dad || !mum || (!mum->parent && dad))
return (binary_trees_ancestor(first, dad));
else if (mum == second || !dad || (!dad->parent && mum))
return (binary_trees_ancestor(mum, second));
return (binary_trees_ancestor(mum, dad));
}
