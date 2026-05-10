class Solution {
public:
    int characterReplacement(string s, int k) {

    int left = 0;
    int right = 0;
    int maxLength = 0;
    int maxChar = 0;
    map<char, int> mp;

    while (right < s.size())
    {
        mp[s[right]]++;

        maxChar = max(maxChar, mp[s[right]]);

        int requiredChangedChar = (right - left + 1) - maxChar;

        if (requiredChangedChar > k) {
            mp[s[left]]--;
            left++;
        }
        maxLength = max(maxLength, (right - left + 1));
        right++;
    }

    return maxLength;
    }
};
