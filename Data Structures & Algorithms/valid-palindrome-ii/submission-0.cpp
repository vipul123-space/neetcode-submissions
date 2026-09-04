class Solution {
   public:
    bool helper(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        if (s.length() == 1) {
            return true;
        }

        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                bool checkRemLeft = helper(
                    s, left + 1,
                    right);  // check by exculding the right character and check for palindrome
                bool checkRemRight = helper(
                    s, left,
                    right - 1);  // check by exculding the left character and check for palindrome

                return checkRemLeft || checkRemRight;
            } else {
                left++;
                right--;
            }
        }

        return true;
    }
};