class Solution {
public:
    int sqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        double p = (1 + x) / 2.0;
        while (true) {
            double np = (p + x / p) / 2.0;
            if (fabs(np - p) < 0.1) {
                return fabs(np);
            }
            p = np;
        }
    }
};
