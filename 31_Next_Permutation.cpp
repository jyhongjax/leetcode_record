# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <sstream>

using namespace std;

class Solution 
{
public:
	void nextPermutation(vector<int>& nums) 
	{
		int i = 0, j = 0;
		bool flag = true;
		int length = int(nums.size());
		for (i = length - 1; flag && i >= 0; --i)
		{
			for (j = length - 1; j > i; --j)
			{
				if (nums[j] > nums[i])
				{
					swap(nums[i], nums[j]);
					sort(nums.begin() + i + 1, nums.end());
					flag = false;
					break;
				}
			}
		}
		if (i == -1 && j == 0)
		{
			sort(nums.begin(), nums.end());
		}
		return;
	}
};

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);
	int temp = 0;
	vector<int> nums;
	while (is >> temp)
	{
		nums.push_back(temp);
	}
	Solution so;
	so.nextPermutation(nums);
	for (int i = 0; i<int(nums.size()); ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}