#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes.
 * Otherwise NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	const binary_tree_t *ancestors_set[1024];
	size_t first_ancestors_count = 0, i;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Traverse the ancestors of the first node and add them to the set */
	while (first != NULL)
	{
		ancestors_set[first_ancestors_count++] = first;
		first = first->parent;
	}

	/* Traverse the ancestors of the second node and check for common ancestor */
	while (second != NULL)
	{
		for (i = 0; i < first_ancestors_count; i++)
		{
			if (second == ancestors_set[i])
				return ((binary_tree_t *)second);
		}
		second = second->parent;

	}

	/* No common ancestors */
	return (NULL);

}
