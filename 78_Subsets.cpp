#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > subsets(vector<int>& nums) 
    {
        vector<vector<int> > result;
        result.push_back(vector<int>());
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int n = (int)result.size();
            for (int j = 0; j < n; ++j)
            {
                vector<int> temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
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
    vector<vector<int> > result = s.subsets(nums);
    for (int i = 0; i < (int)result.size(); ++i)
    {
        for (int j = 0; j < (int)result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}