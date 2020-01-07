# include <iostream>
# include <vector>

using namespace std;

class Solution 
{
public:
	bool canJump(vector<int>& nums) 
	{
		int l = nums.size();
		if (l < 2)
		{
			return true;
		}
		int right = l - 1;
		for (int i = l - 2; i > 0; --i)
		{
			if (nums[i] >= (right - i))
			{
				right = i;
			}
		}
		return nums[0] >= right;
	}
};

int main()
{
	int n = 0, temp = 0;
	vector<int> nums;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	Solution s;
	cout << s.canJump(nums) << endl;
	return 0;
}