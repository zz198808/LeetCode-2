/**
 * time in O(n^2logn) memory in O(n)
 * 1. enumerate every points
 * 2.   calc slope of point (include itself) to this point, and save in slopes vector
 *      notice 1: maybe multiple points are in same position, so we use a base variable to record this
 *      notice 2: maybe slope is null when x equals x, so we use a cnt variable to record 
 * 3. sort slopes and max count of same slope value
 *      notice 1: compare double cannot use =, and use fabs(a - b) < epsilon
 *      notice 2: how to choose epsilon, think 1 / (y1 - y2), y1 - y2 = - 2^32 = 0.000000000232(ten zero), so 1e-11 is enough
 */


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            int cnt = 0;
            int base = 0;
            vector<double> slopes;
            for (int j = 0; j < points.size(); ++j) {
                if (points[i].x == points[j].x) {
                    cnt++;
                    if (points[i].y == points[j].y) {
                        base++;
                    }
                } else {
                    slopes.push_back((static_cast<double>(points[j].y) - points[i].y) 
                      / (static_cast<double>(points[j].x) - points[i].x));
                }
            }
            ans = max(ans, cnt);
            
            if (slopes.size() != 0) {
                sort(slopes.begin(), slopes.end());
                int j = 1;
                cnt = 1;
                while (j < slopes.size()) {
                    if (fabs(slopes[j] - slopes[j - 1]) < 1e-12) {
                        cnt++;
                    } else {
                        ans = max(ans, cnt + base);
                        cnt = 1;
                    }
                    j++;
                }
                ans = max(ans, cnt + base);
            }
        }

        return ans;
    }
};