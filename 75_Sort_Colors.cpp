#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n = (int)nums.size() - 1;
        int loc1 = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (nums[i] == 2)
            {
                int j = n;
                for (; j > i; --j)
                {
                    if (nums[j] != 2)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                n = j - 1;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[loc1]);
                loc1++;
            }
        }
        return;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < n; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}