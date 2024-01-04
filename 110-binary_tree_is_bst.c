#include "binary_trees.h"

/**
 * is_bst_recursive - helper function to check if a binary tree is a valid BST
 * @tree: a pointer to the root node of the tree to check
 * @min: a pointer to the minimum value that a node in the subtree can take
 * @max: a pointer to the maximum value that a node in the subtree can take
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_recursive(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_recursive(tree->left, min, tree->n) &&
			is_bst_recursive(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Description:
 * Properties of a Binary Search Tree:
 * The left subtree of a node contains only nodes with values less than
 * the node’s value
 * The right subtree of a node contains only nodes with values greater than
 * the node’s value
 * The left and right subtree each must also be a binary search tree
 * There must be no duplicate values
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	return (is_bst_recursive(tree, INT_MIN, INT_MAX));

}
