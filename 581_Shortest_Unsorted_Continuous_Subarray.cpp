//# include <iostream>
//# include <vector>
//# include <algorithm>
//
//using namespace std;
//
//class Solution 
//{
//public:
//	int findUnsortedSubarray(vector<int>& nums) 
//	{
//		int l = nums.size();
//		if (l < 1)
//		{
//			return 0;
//		}
//		int i = 1;
//		while (i < l && nums[i] >= nums[i - 1])
//		{
//			++i;
//		}
//		if (i == l)
//		{
//			return 0;
//		}
//		int left = i, right = i;
//		int max_num = nums[i - 1], min_num = nums[i];
//		for (i = i+1; i < l; ++i)
//		{
//			if (nums[i] < max_num)
//			{
//				right = i;
//				min_num = min(min_num, nums[i]);
//			}
//			else
//			{
//				max_num = nums[i];
//			}
//		}
//		for (i = 0; i < left; ++i)
//		{
//			if (nums[i] > min_num)
//			{
//				left = i;
//				break;
//			}
//		}
//		return right - left + 1;
//	}
//};
//
//int main()
//{
//	int n = 0;
//	int temp = 0;
//	cin >> n;
//	vector<int> nums;
//	while (n--)
//	{
//		cin >> temp;
//		nums.push_back(temp);
//	}
//	Solution s;
//	cout << s.findUnsortedSubarray(nums) << endl;
//	return 0;
//}