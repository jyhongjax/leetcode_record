#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int maximalSquare(vector<vector<char>>& matrix) 
	{
		int rows = matrix.size();
		if (rows < 1)
		{
			return 0;
		}
		int cols = matrix[0].size();
		if (cols < 1)
		{
			return 0;
		}
		vector<vector<int> > dp(rows, vector<int>(cols, 0));
		int max_area = 0;
		int area = 0;
		for (int i = rows - 1; i >= 0; --i)
		{
			for (int j = cols - 1; j >= 0; --j)
			{
				if (matrix[i][j] == '0')
				{
					continue;
				}
				dp[i][j] = 1;
				if (i != rows - 1 && j != cols - 1)
				{
					dp[i][j] += min(dp[i + 1][j], dp[i][j + 1]);
					if (dp[i + 1][j] == dp[i][j + 1] && matrix[i + dp[i + 1][j]][j + dp[i + 1][j]] == '0')
					{
						--dp[i][j];
					}
				}
				area = dp[i][j] * dp[i][j];
				if (area > max_area)
				{
					max_area = area;
				}
			}
		}
		return max_area;
	}
};

int main()
{
	int rows = 0, cols = 0;
	cin >> rows >> cols;
	char temp = 0;
	vector<vector<char> > matrix(rows, vector<char>(cols, '0'));
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> temp;
			matrix[i][j] = temp;
		}
	}
	Solution solution;
	cout << solution.maximalSquare(matrix) << endl;
	return 0;
}