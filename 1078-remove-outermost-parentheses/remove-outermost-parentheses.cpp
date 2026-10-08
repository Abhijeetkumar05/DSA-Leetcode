class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> stack;
        string answer;

        for (char c : s) {
            if (c == '(') {
                if (!stack.empty()) {
                    answer.push_back(c);
                }
                stack.push_back(c);
            } else {
                stack.pop_back();
                if (!stack.empty()) {
                    answer.push_back(c);
                }
            }
        }

        return answer;
    }
};