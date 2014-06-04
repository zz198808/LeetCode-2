/*
 * use extra space
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < n; i++) {
            hash[A[i]]++;
        }
        for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
            if (it->second == 1) {
                return it->first;
            }
        }
        
        return 0;
    }
};
