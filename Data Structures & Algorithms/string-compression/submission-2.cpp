class Solution {
   public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) {
            return 1;
        }

        string str = "";
        char currChar = chars[chars.size() - 1];
        int currCount = 1;

        for (int i = chars.size() - 2; i >= 0; i--) {
            if (currChar == chars[i]) {
                currCount++;
            } else {
                string temp = "";

                temp += currChar;

                if (currCount > 1) {
                    temp += to_string(currCount);
                }

                str = temp + str;

                currCount = 1;
                currChar = chars[i];
            }
        }

        // Process the first group
        string temp = "";

        temp += currChar;

        if (currCount > 1) {
            temp += to_string(currCount);
        }

        str = temp + str;

        for (int i = 0; i < str.size(); i++) {
            chars[i] = str[i];
        }

        return str.size();
    }
};