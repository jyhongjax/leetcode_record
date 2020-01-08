// Stupid Solution

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int> > merge1(vector<vector<int> >& intervals)
    {
        vector<vector<int> > ori_vec = intervals;
        vector<vector<int> > result;
        bool ff = true;
        while (ff)
        {
            ff = false;
            for (int i = 0; i < (int)ori_vec.size(); ++i)
            {
                bool f = true;
                for (int j = 0; j < (int)result.size(); ++j)
                {
                    if ((ori_vec[i][0] <= result[j][0] && ori_vec[i][1] >= result[j][0]) ||
                        (ori_vec[i][0] <= result[j][1] && ori_vec[i][1] >= result[j][1]) ||
                        (result[j][0] <= ori_vec[i][0] && result[j][1] >= ori_vec[i][0]) ||
                        (result[j][0] <= ori_vec[i][1] && result[j][1] >= ori_vec[i][1]))
                    {
                        result[j][0] = min(ori_vec[i][0], result[j][0]);
                        result[j][1] = max(ori_vec[i][1], result[j][1]);
                        f = false;
                        ff = true;
                    }
                }
                if (f)
                {
                    vector<int> tempvec(2);
                    tempvec[0] = ori_vec[i][0];
                    tempvec[1] = ori_vec[i][1];
                    result.push_back(tempvec);
                }
            }
            ori_vec = result;
            result = vector<vector<int> >();
        }
        return ori_vec;
    }

    vector<vector<int> > merge2(vector<vector<int> >& intervals, int min_num, int max_num)
    {
        vector<bool> rec(max_num - min_num, false);
        vector<bool> rec_point(max_num - min_num + 1, false);
        vector<vector<int> > result;
        vector<int> temp;
        for (int i = 0; i < (int)intervals.size(); ++i)
        {
            if (intervals[i][0] == intervals[i][1])
            {
                rec_point[intervals[i][0] - min_num] = true;
            }
            for (int j = intervals[i][0]; j < intervals[i][1]; ++j)
            {
                rec[j - min_num] = true;
            }
        }
        for (int i = 0; i < (int)rec_point.size(); ++i)
        {
            if (rec_point[i])
            {
                if ((i - 1 >= 0 && rec[i - 1]) || (i < (int)rec.size() && rec[i]))
                {
                    rec_point[i] = false;
                }
            }
        }
        for (int i = 0; i < (int)rec.size(); ++i)
        {
            if (rec[i])
            {
                if (temp.empty())
                {
                    temp.push_back(i + min_num);
                    temp.push_back(i + min_num + 1);
                }
                else
                {
                    temp[1] = i + 1 + min_num;
                }
            }
            else
            {
                if (!temp.empty())
                {
                    result.push_back(temp);
                    temp = vector<int>();
                }
            }
        }
        if (!temp.empty())
        {
            result.push_back(temp);
            temp = vector<int>();
        }
        for (int i = 0; i < (int)rec_point.size(); ++i)
        {
            if (rec_point[i])
            {
                result.push_back(vector<int>(2, i + min_num));
            }
        }
        return result;
    }

    vector<vector<int> > merge(vector<vector<int> >& intervals)
    {
        vector<vector<int> > result;
        if ((int)intervals.size() < 1)
        {
            return result;
        }
        int min_num = intervals[0][0];
        int max_num = intervals[0][1];
        for (int i = 0; i < (int)intervals.size(); ++i)
        {
            min_num = min(min_num, intervals[i][0]);
            max_num = max(max_num, intervals[i][1]);
        }
        if (max_num - min_num >= (int)intervals.size())
        {
            result = merge1(intervals);
        }
        else
        {
            result = merge2(intervals, min_num, max_num);
        }
        return result;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<int> > intervals(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i][0];
        cin >> intervals[i][1];
    }
    Solution s;
    vector<vector<int> > result = s.merge(intervals);
    for (int i = 0; i < (int)result.size(); ++i)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}