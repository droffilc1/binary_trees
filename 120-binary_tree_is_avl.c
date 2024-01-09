#include "binary_trees.h"

/**
 * binary_tree_level - auxiliary level
 * @tree: pointer to root\
 *
 * Return: integer with level
 */
int binary_tree_level(const binary_tree_t *tree)
{
	int hl, hr;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	hl = binary_tree_level(tree->left);
	hr = binary_tree_level(tree->right);
	if (hl > hr)
		return (hl + 1);
	else
		return (hr + 1);
}

/**
 * get_balance - calculate balance factor
 * @tree: pointer to root
 *
 * Return: integer with balance factor
 */
int get_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_level(tree->left) - binary_tree_level(tree->right));
}

/**
 * bavl - Check level
 * @tree: pointer to root
 * @min: min value
 * @max: max value
 *
 * Return: 1 if is AVL, 0 otherwise
 */
int bavl(const binary_tree_t *tree, int min, int max)
{
	int balance_left, balance_right, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	balance = get_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	balance_left = bavl(tree->left, min, tree->n - 1);
	balance_right = bavl(tree->right, tree->n + 1, max);
	if (balance_left == 1 && balance_right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));
}
