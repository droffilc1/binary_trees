#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree:  a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *y, *parent = tree;

	if (tree == NULL)
		return (NULL);

	y = parent->left;
	if (y == NULL)
		return (tree);

	if (y->right)
		y->right->parent = parent;

	parent->left = y->right;
	y->right = parent;
	y->parent = parent->parent;
	parent->parent = y;

	if (y->parent && y->right->parent == parent)
		y->parent->right = y;
	else if (y->parent)
		y->parent->left = y;

	return (y);
}
