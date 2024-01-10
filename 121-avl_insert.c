#include "binary_trees.h"

/**
 * balance - balances an AVL tree
 * @tree: pointer to the root node of the tree to balance
 * @node: pointer to the node to be inserted
 *
 * Return: pointer to the new root node of the tree once balanced
*/
avl_t *balance(avl_t *tree, avl_t *node)
{
	int bf;

	if (tree == NULL)
		return (NULL);

	bf = binary_tree_balance(tree);

	if (bf > 1)
	{
		/* LL rotation */
		if (tree->left->n < node->n)
			tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (bf < -1)
	{
		/* RR rotation */
		if (tree->right->n > node->n)
			tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}
/**
 * insert - Inserts a value in an AVL tree
 * @tree: a pointer to the root node of the AVL tree
 * @node: node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
*/
avl_t *insert(avl_t *tree, avl_t *node)
{
	if (node == NULL)
		return (NULL);

	if (tree == NULL)
		return (node);

	if (tree->n > node->n)
	{
		tree->left = insert(tree->left, node);
		tree->left->parent = tree;
	}
	else if (tree->n < node->n)
	{
		tree->right = insert(tree->right, node);
		tree->right->parent = tree;
	}
	else if (tree->n == node->n)
	{
		free(node);
		node = NULL;
		return (tree);
	}
	return (balance(tree, node));
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);
	*tree = insert(*tree, new_node);
	return (new_node);

}
