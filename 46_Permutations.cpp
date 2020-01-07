# include <iostream>
# include <vector>

using namespace std;

void dfs(vector<vector<int> >& result, const vector<int>& nums, vector<bool> rec, vector<int> cur_nums)
{
    if ((int)cur_nums.size() == (int)nums.size())
    {
        result.push_back(cur_nums);
        return;
    }
    for (int i = 0; i < (int)rec.size(); ++i)
    {
        if (rec[i])
        {
            cur_nums.push_back(nums[i]);
            rec[i] = false;
            dfs(result, nums, rec, cur_nums);
            cur_nums.pop_back();
            rec[i] = true;
        }
    }
    return;
}

class Solution
{
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > result = vector<vector<int> >();
        int len = (int)nums.size();
        vector<bool> rec(len, true);
        vector<int> cur_nums = vector<int>();
        dfs(result, nums, rec, cur_nums);
        return result;
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
    vector<vector<int> > result = s.permute(nums);
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