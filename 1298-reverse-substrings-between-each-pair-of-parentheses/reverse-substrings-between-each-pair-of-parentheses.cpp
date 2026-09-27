class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");

        for (char ch : s) {
            if (ch == '(') {
                st.push("");
            } 
            else if (ch == ')') {
                string temp = st.top();
                st.pop();

                reverse(temp.begin(), temp.end());

                st.top() += temp;
            } 
            else {
                st.top() += ch;
            }
        }

        return st.top();
    }
};