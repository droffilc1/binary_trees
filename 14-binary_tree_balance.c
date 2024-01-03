#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of a binary tree, otherwise 0
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height of a binary tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	/* Find height of both subtrees and use the larger one */
	left_height += 1 + binary_tree_height(tree->left);
	right_height += 1 + binary_tree_height(tree->right);


	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
