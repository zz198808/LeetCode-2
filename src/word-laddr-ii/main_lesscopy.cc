class Solution {
   
    typedef unordered_set<string>::iterator itT;
    typedef unordered_map<const string*, pair<int, vector<const string*>>> faT;
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        faT fa;
        
        dict.insert(start);
        dict.insert(end);

        itT start_it = dict.find(start);
        fa[&(*start_it)] = make_pair(0, vector<const string*>());
        queue<const string*> q;
        q.push(&(*start_it));

        itT end_it = dict.find(end);
        
        while (!q.empty()) {
            const string* p = q.front();
            q.pop();
            if (p == &(*end_it)) {
                break;
            }
            string u = *p;

            string v = u;

            int level = fa[p].first;
            for (int i = 0; i < v.size(); i++) {
                char c = v[i];
                for (int j = 'a'; j <= 'z'; j++) {
                    if (j != c) {
                        v[i] = j;
                        itT it = dict.find(v);
                        
                        if (it != dict.end()) {

                            faT::iterator fa_it = fa.find(&(*it));
                            if (fa_it == fa.end()) { 
                                vector<const string*> tmp;
                                tmp.push_back(p);
                                fa[&(*it)] = make_pair(level + 1, tmp);
                                q.push(&(*it));
                            } else if (fa_it->second.first == level + 1) {
                                fa_it->second.second.push_back(p);
                            }
                        }
                        v[i] = c;
                        
                    }
                }
            }
        }
        


        if (fa.find(&(*end_it)) == fa.end()) {
            return ans;
        }
        vector<string> tmp;
        Output(&(*end_it), tmp, fa);
        return ans;
    }
private:
    void Output(const string *it, vector<string> &s, faT &fa)
    {
       s.push_back(*it);
        vector<const string*> &fas = fa[it].second;

        if (fas.size() == 0) {
          vector<string> t(s);
          reverse(t.begin(), t.end());
          ans.push_back(t);
        } else {
          for (int i = 0; i < fas.size(); i++) {
            Output(fas[i], s, fa);
          }
        }
        s.pop_back();
    }

    vector<vector<string>> ans;
};
