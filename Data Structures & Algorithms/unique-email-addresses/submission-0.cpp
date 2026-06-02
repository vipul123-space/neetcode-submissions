class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for (string email : emails) {
            string localName = email.substr(0, email.find('@'));
            localName =
                email.find('+') != string::npos ? email.substr(0, email.find('+')) : localName;
            string domainName = email.substr(email.find('@'));
            localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());
            uniqueEmails.insert(localName + domainName);
        }
        return uniqueEmails.size();
    }
};