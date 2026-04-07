#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of the leftmost leaf
 * @tree: Pointer to the root node
 *
 * Return: Depth
 */
size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree->left != NULL)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * perfect_check - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 * @depth: Depth of leaves
 * @level: Current level
 *
 * Return: 1 if perfect, otherwise 0
 */
int perfect_check(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, depth, level + 1) &&
		perfect_check(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = tree_depth(tree);

	return (perfect_check(tree, depth, 0));
}
