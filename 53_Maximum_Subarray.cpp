# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution 
{
public:
		int maxSubArray(vector<int> & nums) 
		{
			int temp_sum = 0;
			int max_num = nums[0];
			int max_sum = 0;
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				temp_sum += nums[i];
				max_sum = max(max_sum, temp_sum);
				temp_sum = max(temp_sum, 0);
				max_num = max(max_num, nums[i]);
			}
			if (max_num <= 0)
			{
				return max_num;
			}
			return max_sum;
		}
};

int main()
{
	int n = 0;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	Solution s;
	cout << s.maxSubArray(nums) << endl;
	return 0;
}