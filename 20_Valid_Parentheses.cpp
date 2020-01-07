# include <iostream>
# include <string>
# include <stack>

using namespace std;

class Solution 
{
public:
	bool isValid(string s) 
	{
		stack<char> st;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st.push(s[i]);
			}
			else
			{
				if (st.empty())
				{
					return false;
				}
				char temp = st.top();
				if ((temp == '(' && s[i] == ')') || (temp == '[' && s[i] == ']') || (temp == '{' && s[i] == '}'))
				{
					st.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (!st.empty())
		{
			return false;
		}
		return true;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution so;
	if (so.isValid(s))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}