#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree:  a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *y, *parent = tree;

	if (tree == NULL)
		return (NULL);

	y = parent->right;
	if (y == NULL)
		return (tree);

	if (y->left)
		y->left->parent = parent;

	parent->right = y->left;
	y->left = parent;
	y->parent = parent->parent;
	parent->parent = y;

	if (y->parent && y->left->parent == parent)
		y->parent->left = y;
	else if (y->parent)
		y->parent->right = y;

	return (y);
}
