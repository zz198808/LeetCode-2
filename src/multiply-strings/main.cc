class Solution {
public:
  string multiply(string num1, string num2)
  {
    bigint b1 = ToBigint(num1), b2 = ToBigint(num2);
    bigint res(b1.size() + b2.size(), 0);
    for (int i = 0; i < b1.size(); i++) {
      for (int j = 0; j < b2.size(); j++) {
        int64_t val = (int64_t)b1[i] * b2[j] + res[i + j];
        res[i + j + 1] += val / BASE;
        res[i + j] = val % BASE;
      }
    }
    return ToString(res);
  }
private:
  typedef vector<int32_t> bigint;
  static const int DIGIT = 9;
  static const int BASE = 1000000000;

  string ToString(const bigint &num)
  {
    string ret;
    int i = num.size() - 1;

    while (i > 0 && num[i] == 0) {
      i--;
    }
    for (int j = 0; j <= i; j++) {
      int32_t c = num[j];

      int cnt = 0;
      do {
        ret = ret + static_cast<char>(c % 10 + '0');
        c /= 10;
        cnt++;
      } while(c);
      while (j < i && cnt < DIGIT) {
        ret = ret + '0';
        cnt++;
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  bigint ToBigint(const string &num)
  {
    bigint ret;
    for (int i = num.length() - 1; i >= 0; i -= DIGIT) {
      int32_t val = 0;
      for (int j = max(i - DIGIT + 1, 0); j <= i; j++) {
        val = val * 10 + num[j] - '0';
      }
      ret.push_back(val);
    }
    return ret;
  }
};

