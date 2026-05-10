class Solution {
public:
 vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> ans;

void helper(string digits, int idx, string str)
{
    if (idx == digits.size())
    { // base case: formed a full combination
        ans.push_back(str);
        return;
    }

    int num = digits[idx] - '0'; // current digit
    string chars = arr[num];     // possible letters for this digit

    for (char c : chars)
    {
        helper(digits, idx + 1, str + c); // choose one char and move to next digit
    }
}

vector<string> letterCombinations(string digits)
{
    ans.clear();
    if (digits.empty())
        return ans;
    helper(digits, 0, "");
    return ans;
}

};
