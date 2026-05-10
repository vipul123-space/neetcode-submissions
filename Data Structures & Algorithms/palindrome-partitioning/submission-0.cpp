class Solution {
public:
    vector<vector<string>> ans;

bool isPalindrome(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
void helper(string &s, vector<string> &temp, int start)
{
    if (start == s.size())
    {
        ans.push_back(temp);
        return;
    }

    for (int end = start; end < s.size(); end++)
    {
        if (isPalindrome(s, start, end))
        {

            temp.push_back(s.substr(start, end - start + 1));
            helper(s, temp, end + 1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> temp;
    helper(s, temp, 0);

    return ans;
}
};
