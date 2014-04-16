class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> vals; 
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b = vals.top();
                vals.pop();
                int a = vals.top();
                vals.pop();
                int c;
                switch (tokens[i][0]) {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                }
                vals.push(c);
            } else {
                vals.push(atoi(tokens[i].c_str()));
            }
        }
        return vals.top();
    }
};