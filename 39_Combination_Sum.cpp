# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>

using namespace std;

struct MyNode
{
    vector<int> numbers;
    int sum = 0;
};

void dfs(vector<int>& candidates, int target, int index, MyNode mn, vector<vector<int> >& result)
{
    if (mn.sum == target)
    {
        result.push_back(mn.numbers);
    }
    for (int i = index; i < (int)candidates.size(); ++i)
    {
        if (mn.sum + candidates[i] > target)
        {
            return;
        }
        else
        {
            MyNode temp_node = mn;
            temp_node.numbers.push_back(candidates[i]);
            temp_node.sum += candidates[i];
            dfs(candidates, target, i, temp_node, result);
        }
    }
    return;
}

class Solution 
{
public:
        vector<vector<int> > combinationSum(vector<int> & candidates, int target) 
        {
            vector<vector<int> > result;
            sort(candidates.begin(), candidates.end());
            queue<MyNode> mnq;
            for (int i = 0; i < (int)candidates.size(); ++i)
            {
                if (candidates[i] > target)
                {
                    break;
                }
                MyNode mn;
                mn.numbers = vector<int>(1, candidates[i]);
                mn.sum = candidates[i];
                dfs(candidates, target, i, mn, result);
            }
            return result;
        }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<int> candidates(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> candidates[i];
    }
    int target = 0;
    cin >> target;
    Solution s;
    vector<vector<int> > result = s.combinationSum(candidates, target);
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