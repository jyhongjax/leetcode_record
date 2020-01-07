# include <iostream>
# include <string>
# include <vector>
# include <queue>

using namespace std;

struct StringInQueue
{
	string s;
	int l_number = 0;
	int r_number = 0;
	StringInQueue(string s_in, int l_number_in, int r_number_in)
	{
		s = s_in;
		l_number = l_number_in;
		r_number = r_number_in;
	}
};

class Solution 
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> result;
		queue<StringInQueue> s_que;
		s_que.push(StringInQueue(string(), 0, 0));
		while (!s_que.empty())
		{
			StringInQueue temp = s_que.front();
			if (temp.l_number + temp.r_number == 2 * n)
			{
				result.push_back(temp.s);
			}
			else
			{
				if (temp.l_number == n)
				{
					s_que.push(StringInQueue(temp.s + ")", temp.l_number, temp.r_number + 1));
				}
				else if (temp.l_number == temp.r_number)
				{
					s_que.push(StringInQueue(temp.s + "(", temp.l_number + 1, temp.r_number));
				}
				else
				{
					s_que.push(StringInQueue(temp.s + ")", temp.l_number, temp.r_number + 1));
					s_que.push(StringInQueue(temp.s + "(", temp.l_number + 1, temp.r_number));
				}
			}
			s_que.pop();
		}
		return result;
	}
};

int main()
{
	int n = 0;
	cin >> n;
	Solution s;
	vector<string> result = s.generateParenthesis(n);
	for (int i = 0; i < (int)size(result); ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}