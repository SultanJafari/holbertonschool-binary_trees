#include "binary_trees.h"

/**
 * depth - Measures the depth of a leaf node in a binary tree
 * @tree: Pointer to the node
 *
 * Return: The depth of the leaf
 */
static size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect - Recursive helper to check if a tree is perfect
 * @tree: Pointer to the root node
 * @d: The depth of the leftmost leaf
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
static int is_perfect(const binary_tree_t *tree, size_t d, size_t level)
{
	if (!tree)
		return (1);

	/* Check if it is a leaf */
	if (!tree->left && !tree->right)
		return (d == level + 1);

	/* If one child is missing, it's not perfect */
	if (!tree->left || !tree->right)
		return (0);

	/* Recurse for both subtrees */
	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_perfect(tree, depth(tree), 0));
}
