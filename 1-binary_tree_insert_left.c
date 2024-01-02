#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 *
 * If parent already has a left-child, the new node must take its place, and
 * the old left-child must be set as the left-child of the new node.
 *  Return: A pointer to the new node. Otherwise NULL.
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	/* Create a new node with the given value */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Check if parent already has a left child */
	if (parent->left != NULL)
	{
		/* Set new node's left child to the current left child of the parent */
		new_node->left = parent->left;
		/* Set the parent of the current left child to the new node */
		parent->left->parent = new_node;
	}
	/* Set the left child of the parent to the new node */
	parent->left = new_node;
	/* Set the parent of the new node to the given parent */
	new_node->parent = parent;

	return (new_node);
}
