// 9.5 Inorder traversal with O(1) space, nodes have explicit parent field

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

class Traversal
{
	public:
		void inorder(TreeNode *root)
		{
			TreeNode *t = root;
			while (t != NULL)
			{
				if (t->left == NULL)
				{
					cout << t->val << " ";
					if (t->right == NULL)
					{
						while (t != NULL && t->parent->right == t)
						{
							t = t->parent;
						}
						if (t == NULL)
						{
							break;
						}
						else
						{
							t = t->parent;
							cout << t->val << " ";
						}
					}
					t = t->right;
				}
				else
				{
					t = t->left;
				}
			}
			cout << endl;
		}
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
