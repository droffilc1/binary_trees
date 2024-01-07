#include "binary_trees.h"

/**
 * bst_find_min - finds the minimum value
 * @node: pointer to the node
 *
 * Return: minimum value, otherwise NULL
 */
bst_t *bst_find_min(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = bst_find_min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
