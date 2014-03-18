// 8.3 Printing the keys in a BST, no recursion

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Morris
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
					t = t->right;
				}
				else
				{
					TreeNode *p = t->left;
					for (; p->right != NULL && p->right != t; p = p->right);

					if (p->right == NULL)
					{
						p->right = t;
						t = t->left;
					}
					else
					{
						cout << t->val << " ";
						p->right = NULL;
						t = t->right;
					}
				}
			}
			cout << endl;
		}
};

int main()
{
	TreeNode *root = new TreeNode(100);
	root->left = new TreeNode(50);
	root->left->right = new TreeNode(60);
	root->left->right->left = new TreeNode(55);
	root->left->right->right = new TreeNode(65);
	root->right = new TreeNode(150);
	root->right->left = new TreeNode(120);
	root->right->left->right = new TreeNode(130);
	root->right->left->right->right = new TreeNode(140);

	Morris morris;
	morris.inorder(root);

	return 0;
}
