class Solution {
public:

    string encode(vector<string>& strs) {
           string ans = "";
    for (string s : strs) {
        string strLen = to_string(s.size());
        ans += (strLen + "#" + s);
    }
    return ans;

    }

    vector<string> decode(string s) {
         vector<string> ans;
    int i = 0;
    while (i < s.size()) {
        int pos = s.find('#', i);
        if (pos == string::npos)break;
        int length = stoi(s.substr(i, pos - i));
        string str = s.substr(pos + 1, length);
        ans.push_back(str);
        i = pos + 1 + length;
    }
    return ans;
    }
};
