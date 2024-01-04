#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	const binary_tree_t *queue[1024], *current;

	if (tree == NULL || func == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
