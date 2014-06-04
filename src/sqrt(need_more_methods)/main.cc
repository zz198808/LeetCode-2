class Solution {
public:
    int sqrt(int x) {
        int l = 0, r = 46341;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};


class Solution2 {
public:
    int sqrt(int x) {
        long long l = 0, r = 1 << 16;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};

