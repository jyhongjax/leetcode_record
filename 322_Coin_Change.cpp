# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution 
{
public:
	int coinChange(vector<int>& coins, int amount) 
	{
		vector<int> dp(amount + 1, amount + 1);
		sort(coins.begin(), coins.end());
		dp[0] = 0;
		int l = coins.size();
		for (int i = 1; i <= amount; ++i)
		{
			for (int j = 0; j < l; ++j)
			{
				if (coins[j] <= i)
				{
					dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
				}
				else
				{
					break;
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};

int main()
{
	int n = 0, temp = 0, amount = 0;
	vector<int> coins;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		coins.push_back(temp);
	}
	cin >> amount;
	Solution s;
	cout << s.coinChange(coins, amount) << endl;
	return 0;
}