#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res(2, -1);
		int l = 0;
		int r = nums.size() - 1;
		int mid = 0;

		// find left
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (r >= 0 && nums[r] == target)
		{
			res[0] = r;
		}
		else if (l < nums.size() && nums[l] == target)
		{
			res[0] = l;
		}
		else 
		{
			return res;
		}

		l = 0;
		r = nums.size() - 1;
		//find right
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (nums[mid] <= target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (l < nums.size() && nums[l] == target)
		{
			res[1] = l;
		}
		else if (r >= 0 && nums[r] == target)
		{
			res[1] = r;
		}
		return res;
	}
};

int main()
{
	int n = 0, temp = 0;
	cin >> n;
	vector<int> nums;
	while (n--)
	{
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> temp;
	Solution solution;
	vector<int> result = solution.searchRange(nums, temp);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}