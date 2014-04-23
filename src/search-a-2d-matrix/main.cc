class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (0 == matrix.size()) {
            return false;
        }
        int n = matrix.size(), m = matrix[0].size();
        
        if (0 == m) {
            return false;
        }
        
        int l = 0, r = n * m;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            int x = mid / m, y = mid % m;
            if (matrix[x][y] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l < n * m) {
            return matrix[l / m][l % m] == target;
        } else {
            return false;
        }
    }
};
