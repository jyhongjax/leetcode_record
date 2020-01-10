#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        if (m < 2 || n < 2)
        {
            return 1;
        }
        vector<vector<int> > rec(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                rec[i][j] = rec[i][j - 1] + rec[i - 1][j];
            }
        }
        return rec[m - 1][n - 1];
    }
};

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
    return 0;
}