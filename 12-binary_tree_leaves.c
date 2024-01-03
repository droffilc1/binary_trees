#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: count the leaves in a binary tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	while (tree->left == NULL && tree->right == NULL)
	{
		binary_tree_leaves(tree->left);
		binary_tree_leaves(tree->right);
		count++;
	}
	return (count);
}
