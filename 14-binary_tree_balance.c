#include "binary_trees.h"

/**
 * measure_height - Measures the height of a binary tree for balance factor
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
static size_t measure_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + measure_height(tree->left);
	else
		left_height = 1;

	if (tree->right != NULL)
		right_height = 1 + measure_height(tree->right);
	else
		right_height = 1;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = (int)measure_height(tree->left);

	if (tree->right != NULL)
		right_h = (int)measure_height(tree->right);

	return (left_h - right_h);
}
