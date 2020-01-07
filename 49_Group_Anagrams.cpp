# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>

using namespace std;

bool operator== (const vector<int>& v1, const vector<int>& v2)
{
    if ((int)v1.size() != (int)v2.size())
    {
        return false;
    }
    for (int i = 0; i < (int)v1.size(); ++i)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

struct MyHash
{
    size_t operator()(vector<int> v) const
    {
        int temp = v[0];
        size_t result = hash<int>()(temp);
        for (int i = 1; i < v.size(); ++i)
        {
            result = hash<int>()(result + hash<int>()(v[i]));
        }
        return result;
    }
};

class Solution 
{
public:
    vector<int> getFrequencyOfLetters(string letters)
    {
        vector<int> frequency_of_letters(26, 0);
        for (int i = 0; i < (int)letters.size(); ++i)
        {
            frequency_of_letters[(int)(letters[i] - 'a')] += 1;
        }
        return frequency_of_letters;
    }

    vector<vector<string> > groupAnagrams(vector<string>& strs) 
    {
        unordered_map<vector<int>, int, MyHash> rec;
        vector<vector<string> > result;
        for (int i = 0; i < (int)strs.size(); ++i)
        {
            vector<int> frequency_of_letters = getFrequencyOfLetters(strs[i]);
            auto p = rec.find(frequency_of_letters);
            if (p == rec.end())
            {
                result.push_back(vector<string>());
                int idx = (int)result.size() - 1;
                result[idx].push_back(strs[i]);
                rec[frequency_of_letters] = idx;
            }
            else
            {
                result[rec[frequency_of_letters]].push_back(strs[i]);
            }
        }
        return result;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<string> strs;
    string temp_string;
    while (n--)
    {
        cin >> temp_string;
        strs.push_back(temp_string);
    }
    Solution s;
    vector<vector<string> > result = s.groupAnagrams(strs);
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