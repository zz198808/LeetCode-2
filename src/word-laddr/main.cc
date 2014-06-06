class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        
      
        q.push(make_pair(start, 0));
        dict.erase(start);
        
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == end) {
                return p.second + 1;
            }
            
            for (int i = 0; i < p.first.size(); i++) {
                char c = p.first[i];
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j != c) {
                        p.first[i] = j;
                        
                        unordered_set<string>::iterator it = dict.find(p.first);
                        
                        if (it != dict.end()) {
                            q.push(make_pair(*it, p.second + 1));
                            dict.erase(it);
                        }
                        
                        p.first[i] = c;
                    }
                }
            }
            
            
        }
        
        return 0;
        
    }
};
