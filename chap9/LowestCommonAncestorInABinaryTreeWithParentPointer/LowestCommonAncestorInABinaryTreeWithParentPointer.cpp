// 9.12 Lowest common ancestor in a binary tree, with parent pointer

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), parent(NULL), left(NULL), right(NULL) {}
};

// TODO
class Solution
{
	public:
};

int main()
{
	TreeNode *root = new TreeNode(100);
	root->left = new TreeNode(50);
	root->left->parent = root;
	root->left->right = new TreeNode(60);
	root->left->right->parent = root->left;
	root->left->right->left = new TreeNode(55);
	root->left->right->left->parent = root->left->right;
	root->left->right->right = new TreeNode(65);
	root->left->right->right->parent = root->left->right;
	root->right = new TreeNode(150);
	root->right->parent = root;
	root->right->left = new TreeNode(120);
	root->right->left->parent = root->right;
	root->right->left->right = new TreeNode(130);
	root->right->left->right->parent = root->right->left;
	root->right->left->right->right = new TreeNode(140);
	root->right->left->right->right->parent = root->right->left->right;

	Traversal traversal;
	traversal.inorder(root);

	return 0;
}
