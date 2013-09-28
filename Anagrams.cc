class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<int> > anagram_groups;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            anagram_groups[key].push_back(i);
        }
        vector<string> res;
        for (map<string, vector<int> >::iterator it = anagram_groups.begin();
             it != anagram_groups.end();
             it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++) {
                    res.push_back(strs[it->second[i]]);
                }
            }
        }
        return res;
    }
};
