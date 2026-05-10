class Solution {
public:
int maxDifference(string s)
{
    unordered_map<char, int> mp;

    for (char ch : s)
    {
        mp[ch]++;
    }
    int oddFreq = 0;
    int evenFreq = INT_MAX;
    int ans = 0;
    for (auto ele : mp)
    {
        if (ele.second % 2 != 0)
        {
            oddFreq = max(oddFreq, ele.second);
        }
        else
        {
            evenFreq = min(evenFreq, ele.second);
        }
    }

    return oddFreq - evenFreq;
}

};