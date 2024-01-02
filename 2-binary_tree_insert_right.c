#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * If parent already has a right-child, the new node must take its place, and
 * the old right-child must be set as the right-child of the new node.
 *  Return: A pointer to the new node. Otherwise NULL.
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Check if parent already has a right child */
	if (parent->right != NULL)
	{
		/* Set new node's right child as the right child of the parent */
		new_node->right = parent->right;
		/* Set the parent of the current right child as the new node */
		parent->right->parent = new_node;
	}
	/* Set the left child of the parent as the new node */
	parent->right = new_node;
	/* Set the parent of the new node to the given parent */
	new_node->parent = parent;

	return (new_node);
}
