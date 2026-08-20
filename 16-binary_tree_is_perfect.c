#include "binary_trees.h"

/**
 * tree_is_perfect - Helper function that checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: Depth of the tree
 * @level: Current level in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int tree_is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (tree_is_perfect(tree->left, depth, level + 1) &&
		tree_is_perfect(tree->right, depth, level + 1));
}

/**
 * get_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node to measure the depth
 *
 * Return: Depth of the tree
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree);
	return (tree_is_perfect(tree, depth, 0));
}
