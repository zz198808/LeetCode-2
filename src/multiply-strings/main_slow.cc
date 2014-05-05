class Solution {
public:
  string multiply(string num1, string num2) {
    string res(num1.length() + num2.length(), '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < num1.size(); i++) {
      int c = 0;
      for (int j = 0; j < num2.size(); j++) {
        int val = ToDigit(res[i + j]) + ToDigit(num1[i]) * ToDigit(num2[j]) + c;
        res[i + j] = (val % 10) + '0';
        c = val / 10;
      }
      res[i + num2.size()] = (ToDigit(res[i + num2.size()]) + c) % 10 + '0';
    }
    int i = res.length();
    while (i > 1 && res[i - 1] == '0') {
      i--;
    }
    res.erase(i, res.length() - i);
    reverse(res.begin(), res.end());
    return res;
  }
private:
  int ToDigit(char s) 
  {
    return s - '0';
  }


  
};
