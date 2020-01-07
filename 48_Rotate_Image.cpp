# include <iostream>
# include <vector>

using namespace std;

class Solution 
{
public:
        void rotate(vector<vector<int>> & matrix) 
        {
            int len = (int)matrix.size();
            if (len < 2)
            {
                return;
            }
            int n = len / 2;
            if (n * 2 != len)
            {
                ++n;
            }
            int rotate_num = len * len / 4;
            for (int idx = 0; idx < rotate_num; ++idx)
            {
                int i = idx / n;
                int j = idx - i * n;
                swap(matrix[i][j], matrix[j][len - 1 - i]);
                swap(matrix[i][j], matrix[len - 1 - i][len - 1 - j]);
                swap(matrix[i][j], matrix[len - 1 - j][i]);
            }
        }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<int> > nums(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> nums[i][j];
        }
    }
    Solution s;
    s.rotate(nums);
    for (int i = 0; i < (int)nums.size(); ++i)
    {
        for (int j = 0; j < (int)nums[i].size(); ++j)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}