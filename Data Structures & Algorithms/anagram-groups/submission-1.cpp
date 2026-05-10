class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    if (strs.size() == 0)
    {
        return {{""}};
    }

    unordered_map<string, vector<string>> mp;

    for (auto str : strs)
    {
        string getCharStr = getFrequencyString(str);

        if (mp.find(getCharStr) != mp.end())
        {
            mp[getCharStr].push_back(str);
        }
        else
        {
            mp[getCharStr].push_back(str);
        }
    }

    vector<vector<string>> res;
    for (auto strArr : mp)
    {
        res.push_back(strArr.second);
    }

    return res;
    }

    string getFrequencyString(string str)
{

    vector<char> freq(27, 0);

    for (auto chr : str)
    {
        freq[chr - 'a']++;
    }

    string ans = "";

    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] != 0)
        {
            char temp = 'a' + i;
            ans += temp + to_string(freq[i]);
        }
    }

    return ans;
}
};
