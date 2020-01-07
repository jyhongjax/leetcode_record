# include <iostream>
# include <vector>
# include <string>
# include <stack>

using namespace std;

struct WordNode
{
	int idx = 0;
	int cur_row = 0;
	int cur_col = 0;
	vector<vector<char>> res;
	WordNode(int idx_in, int cur_row_in, int cur_col_in, vector<vector<char>>& res_in)
	{
		idx = idx_in;
		cur_row = cur_row_in;
		cur_col = cur_col_in;
		res = res_in;
	}
};

class Solution 
{
public:
	bool exist(vector<vector<char>>& board, string word) 
	{
		int rows = board.size();
		if (rows < 1)
		{
			return false;
		}
		int cols = board[0].size();
		if (cols < 1)
		{
			return false;
		}
		int l = word.size();
		if (l < 1)
		{
			return true;
		}
		stack<WordNode> word_stack;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (board[i][j] == word[0])
				{
					vector<vector<char>> temp_board(rows, vector<char>(cols, true));
					temp_board[i][j] = false;
					word_stack.push(WordNode(1, i, j, temp_board));
				}
			}
		}
		while (!word_stack.empty())
		{
			WordNode temp_node = word_stack.top();
			word_stack.pop();
			if (temp_node.idx == l)
			{
				return true;
			}
			if ((temp_node.cur_row > 0) && temp_node.res[temp_node.cur_row - 1][temp_node.cur_col] 
				&& (board[temp_node.cur_row - 1][temp_node.cur_col] == word[temp_node.idx]))
			{
				temp_node.res[temp_node.cur_row - 1][temp_node.cur_col] = false;
				word_stack.push(WordNode(temp_node.idx + 1, temp_node.cur_row - 1, temp_node.cur_col, temp_node.res));
				temp_node.res[temp_node.cur_row - 1][temp_node.cur_col] = true;
			}
			if ((temp_node.cur_row < rows - 1) && temp_node.res[temp_node.cur_row + 1][temp_node.cur_col]
				&& (board[temp_node.cur_row + 1][temp_node.cur_col] == word[temp_node.idx]))
			{
				temp_node.res[temp_node.cur_row + 1][temp_node.cur_col] = false;
				word_stack.push(WordNode(temp_node.idx + 1, temp_node.cur_row + 1, temp_node.cur_col, temp_node.res));
				temp_node.res[temp_node.cur_row + 1][temp_node.cur_col] = true;
			}
			if ((temp_node.cur_col > 0) && temp_node.res[temp_node.cur_row][temp_node.cur_col - 1]
				&& (board[temp_node.cur_row][temp_node.cur_col - 1] == word[temp_node.idx]))
			{
				temp_node.res[temp_node.cur_row][temp_node.cur_col - 1] = false;
				word_stack.push(WordNode(temp_node.idx + 1, temp_node.cur_row, temp_node.cur_col - 1, temp_node.res));
				temp_node.res[temp_node.cur_row][temp_node.cur_col - 1] = true;
			}
			if ((temp_node.cur_col < cols - 1) && temp_node.res[temp_node.cur_row][temp_node.cur_col + 1]
				&& (board[temp_node.cur_row][temp_node.cur_col + 1] == word[temp_node.idx]))
			{
				temp_node.res[temp_node.cur_row][temp_node.cur_col + 1] = false;
				word_stack.push(WordNode(temp_node.idx + 1, temp_node.cur_row, temp_node.cur_col + 1, temp_node.res));
				temp_node.res[temp_node.cur_row][temp_node.cur_col + 1] = true;
			}
		}
		return false;
	}
};

int main()
{
	int n = 0, m = 0;
	char temp = 0;
	cin >> n >> m;
	int idx = 0;
	int num = n * m;
	vector<vector<char>> board(n, vector<char>());
	while (idx < num)
	{
		cin >> temp;
		board[idx / m].push_back(temp);
		++idx;
	}
	string word;
	cin >> word;
	Solution s;
	cout << s.exist(board, word);
	return 0;
}