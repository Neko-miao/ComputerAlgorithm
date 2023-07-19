#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		return Solution0(root);
	}
private:
	TreeNode* Solution0(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		Solution0(root->left);
		Solution0(root->right);
		return root;
	}
};
