class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        
        string tmp;
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                if (tmp.length() != 0) {
                    words.push_back(tmp);
                    tmp = "";
                }
            } else {
                tmp += s[i];
            }
        }
        
        s = "";
        for (vector<string>::reverse_iterator it = words.rbegin(); it != words.rend(); ++it) {
            s += *it;
            if (it + 1 != words.rend()) {
                s += ' ';
            }    
        }
    }
};