class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        for (auto x : knowledge) {
            mp[x[0]] = x[1];
        }

        string org = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '(') {
                org += s[i];
            }
            
            else {
                string key = "";
                i++;  

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.find(key) != mp.end()) {
                    org += mp[key];
                }
                else {
                    org += "?";
                }
            }
        }

        return org;
    }
};