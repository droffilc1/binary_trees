#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height of a binary tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	/* Find height of both subtrees and use the larger one */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	left_height++;
	right_height++;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
