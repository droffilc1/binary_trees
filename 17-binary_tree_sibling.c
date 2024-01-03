#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node:  a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling node. Otherwise NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if node is not the root and has a parent */
	if (node != NULL && node->parent != NULL)
	{
		/* Determine if the node is a left child or right child  */
		if (node->parent->left == node)
			/* If node is a left child, return the right child (sibling)*/
			return (node->parent->right);
		/* If node is a right child, return the left child (sibling)*/
		return (node->parent->left);

	}
	/* If node has no siblings return NULL*/
	return (NULL);
}
