#include "binary_trees.h"

/**
 * binary_tree_size - counts the number of nodes in the binary tree
 * @root: a pointer to the root node of the tree
 *
 * Return: Number of nodes in the binary tree
 */
size_t binary_tree_size(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + binary_tree_size(root->left) + binary_tree_size(root->right));
}

/**
 * check_complete- Recursive helper function
 * @root: pointer to the root of the node
 * @index: Index of the current node
 * @size: total number of node in the tree
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int check_complete(const binary_tree_t *root, size_t index, size_t size)
{
	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (check_complete(root->left, 2 * index + 1, size) &&
			check_complete(root->right, 2 * index + 2, size));

}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if it is complete, otherwise 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (check_complete(tree, 0, size));
}
