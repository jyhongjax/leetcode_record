#include <climits>
# define NULL nullptr

struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
struct Result
{
	bool valid;
	int min_val;
	int max_val;
	Result(bool input_valid, int input_min_val, int input_max_val)
	{
		valid = input_valid;
		min_val = input_min_val;
		max_val = input_max_val;
	}
};

class Solution {
public:
	Result myIsValidBST(TreeNode* root)
	{
		if (root == NULL)
		{
			return Result(true, 0, 0);
		}
		int min_val = root->val, max_val = root->val;
		if (root->left == NULL && root->right == NULL)
		{
			return Result(true, root->val, root->val);
		}
		Result l = myIsValidBST(root->left);
		Result r = myIsValidBST(root->right);
		if (root->left != NULL)
		{
			min_val = l.min_val;
			if (root->val <= l.max_val)
			{
				return Result(false, 0, 0);
			}
		}
		if (root->right != NULL)
		{
			max_val = r.max_val;
			if (root->val >= r.min_val)
			{
				return Result(false, 0, 0);
			}
		}
		return Result(l.valid && r.valid, min_val, max_val);
	}


	bool isValidBST(TreeNode* root)
	{
		return myIsValidBST(root).valid;
	}
};


// ----- Better Solution from Internet ----- //
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode* root, long mn, long mx) {
		if (!root) return true;
		if (root->val <= mn || root->val >= mx) return false;
		return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
	}
};