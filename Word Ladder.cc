// Small: 8ms; Large: 780ms
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int res = 0;
        if (start.empty() || dict.empty()) {
            return res;
        }
        unordered_set<string>::iterator it = dict.find(start);
        if (it != dict.end()) {
            dict.erase(it);
        }
        vector<string> words;
        words.push_back(start);
        int s = 0, e;
        bool found = false;
        while (!found && s < words.size()) {
            res++;
            e = words.size();
            while (!found && s < e) {
                string word = words[s];
                for (int i = 0; !found && i < word.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (word[i] == c) {
                            continue;
                        }
                        swap(word[i], c);
                        if (word == end) {
                            found = true;
                            break;
                        } else {
                            unordered_set<string>::iterator it = dict.find(word);
                            if (it != dict.end()) {
                                words.push_back(word);
                                dict.erase(it);
                            }
                        }
                        swap(word[i], c);
                    }
                }
                s++;
            }
        }
        if (found) {
            res++;
        } else {
            res = 0;
        }
        return res;
    }
};
