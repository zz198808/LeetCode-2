class Solution {
   
    typedef unordered_set<string>::iterator itT;
    typedef unordered_map<string, pair<int, vector<string>>> faT;
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        faT fa;
        
        fa[start] = make_pair(0, vector<string>());
        
        queue<string> q;
        q.push(start);
        dict.insert(start);
        dict.insert(end);
        
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            if (u == end) {
                break;
            }

            string v = u;

            int level = fa[u].first;
            for (int i = 0; i < v.size(); i++) {
                char c = v[i];
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j != c) {
                        v[i] = j;
                        
                        itT it = dict.find(v);
                        
                        if (it != dict.end()) {
                            faT::iterator fa_it = fa.find(v);
                            if (fa_it == fa.end()) { 
                                vector<string> tmp;
                                tmp.push_back(u);
                                fa[v] = make_pair(level + 1, tmp);
                                q.push(v);
                            } else if (fa_it->second.first == level + 1) {
                                fa_it->second.second.push_back(u);
                            }
                        }
                        
                        v[i] = c;
                        
                    }
                }
            }
        }

        if (fa.find(end) == fa.end()) {
            return ans;
        }

        /*

        for (faT::iterator it = fa.begin(); it != fa.end(); ++it) {
          cout << it->first << " " <<  it->second.first << endl;
          for (int j = 0; j < it->second.second.size(); j++) {
            cout << it->second.second[j] << " ";
          }
          cout << endl;
          }*/


        vector<string> tmp;
        Output(end, tmp, fa);
        return ans;
    }
private:
    void Output(const string &u, vector<string> &s, faT &fa)
    {
       s.push_back(u);

        pair<int, vector<string>> &p = fa[u];

        if (p.second.size() == 0) {
          vector<string> t(s);
          reverse(t.begin(), t.end());
          ans.push_back(t);
        } else {
          for (int i = 0; i < p.second.size(); i++) {
            Output(p.second[i], s, fa);
          }
        }
        s.pop_back();
    }

    vector<vector<string>> ans;
};
