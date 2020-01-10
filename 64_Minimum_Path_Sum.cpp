#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        if ((int)grid.size() < 2 && (int)grid[0].size() < 2)
        {
            return grid[0][0];
        }
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i + 1 < m && j + 1 < n)
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
                }
                else if (i + 1 < m)
                {
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                }
                else if (j + 1 < n)
                {
                    dp[i][j] += dp[i][j + 1] + grid[i][j];
                }
                else
                {
                    dp[i][j] = grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    vector<vector<int> > grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}