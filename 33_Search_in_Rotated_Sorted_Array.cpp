# include <iostream>
# include <vector>
# include <string>
# include <sstream>

using namespace std;

class Solution 
{
public:
	int search(vector<int>& nums, int target) 
	{
		int l = 0, r = 0, index = 0;
		r = int(nums.size() - 1);
		if (r < 0)
		{
			return -1;
		}
		while (l <= r)
		{
			index = (l + r) / 2;
			if (nums[index] == target)
			{
				return index;
			}
			else
			{
				if (nums[index] > target)
				{
					if (nums[l] <= target)
					{
						r = index - 1;
					}
					else
					{
						if (nums[index] >= nums[l])
						{
							l = index + 1;
						}
						else
						{
							r = index - 1;
						}
					}
				}
				else
				{
					if (nums[index] >= nums[l])
					{
						l = index + 1;
					}
					else
					{
						if (nums[l] > target)
						{
							l = index + 1;
						}
						else
						{
							r = index - 1;
						}
					}
				}
			}
		}
		return -1;
	}
};

int main()
{
	string s;
	int n = 0, temp = 0;
	vector<int> nums;
	getline(cin, s);
	cin >> n;
	istringstream is(s);
	while (is >> temp)
	{
		nums.push_back(temp);
	}
	Solution so;
	cout << so.search(nums, n);
	return 0;
}