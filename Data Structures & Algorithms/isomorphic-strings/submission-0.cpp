class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST, mapTS;  // Mappings in both directions

        for (int i = 0; i < s.length(); i++) {
            // Get the current characters from both strings
            char charS = s[i], charT = t[i];

            // Check if there is a conflicting mapping in either direction
            if ((mapST.count(charS) && mapST[charS] != charT) ||
                (mapTS.count(charT) && mapTS[charT] != charS)) {
                // If there is a conflict, the strings are not isomorphic
                return false;
            }
            mapST[charS] = charT;
            mapTS[charT] = charS;
        }

        return true;
    }
};