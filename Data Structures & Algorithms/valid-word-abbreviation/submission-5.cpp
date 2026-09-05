class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; // Pointer for word
        int j = 0; // Pointer for abbr

        while (i < word.size() && j < abbr.size()) {
            if (isdigit(abbr[j])) {
                // Check for leading zero
                if (abbr[j] == '0') {
                    return false;
                }
                
                // Parse the full multi-digit number
                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                
                // Skip 'num' characters in 'word'
                i += num;
            } else {
                // If characters don't match, abbreviation is invalid
                if (word[i] != abbr[j]) {
                    return false;
                }
                i++;
                j++;
            }
        }

        // Both pointers must reach the end of their respective strings
        return i == word.size() && j == abbr.size();
    }
};