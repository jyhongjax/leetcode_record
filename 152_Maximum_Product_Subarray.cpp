# include <iostream>
# include <algorithm>
# include <vector>
# include <limits>

using namespace std;

class Solution 
{
public:
	int maxProduct(vector<int>& nums) 
	{
		int l = nums.size();
		int max_product = nums[l - 1];
		int old_max = nums[l - 1];
		int old_min = nums[l - 1];
		for (int i = l-2; i >= 0; --i)
		{
			int temp_prduct_1 = old_max * nums[i];
			int temp_prduct_2 = old_min * nums[i];
			if (temp_prduct_1 >= temp_prduct_2)
			{
				old_max = temp_prduct_1;
				old_min = temp_prduct_2;
			}
			else
			{
				old_max = temp_prduct_2;
				old_min = temp_prduct_1;
			}
			old_max = max(old_max, nums[i]);
			old_min = min(old_min, nums[i]);
			max_product = max(max_product, old_max);
		}
		return max_product;
	}
};

int main()
{
	int temp = 0;
	vector<int> nums;
	while (cin >> temp)
	{
		nums.push_back(temp);
	}
	Solution s;
	cout << s.maxProduct(nums) << endl;
	return 0;
}