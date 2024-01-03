#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node:  a pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node. Otherwise NULL
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Get the grandparent of the node */
	grandparent = node->parent->parent;

	/* Determine if the parent is a left child or right child */
	if (grandparent->left == node->parent)
		/**
		 * If the parent is a left child, return the
		 * right child of grandparent (uncle)
		*/
		return (grandparent->right);

	/**
	 * If the parent is a right child, return the
	 * left child of grandparent (uncle)
	 */
	return (grandparent->left);
}
