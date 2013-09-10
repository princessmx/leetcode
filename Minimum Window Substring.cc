// Small: 12ms; Large: 184ms
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty()) {
            return "";
        }
        count_map_.clear();
        map<char, int>::iterator it;
        for (int i = 0; i < T.size(); i++) {
            it = count_map_.find(T[i]);
            if (it == count_map_.end()) {
                count_map_[T[i]] = 1;
            } else {
                it->second++;
            }
        }
        int start = 0, end, count = T.size();
        int min_size = INT_MAX;
        for (end = 0; end < S.size(); end++) {
            it = count_map_.find(S[end]);
            if (it != count_map_.end()) {
                it->second--;
                if (it->second >= 0) {
                    count--;
                }
            }
            if (count == 0) {
                while (true) {
                    it = count_map_.find(S[start]);
                    if (it != count_map_.end()) {
                        if (it->second < 0) {
                            it->second++;
                        } else {
                            break;
                        }
                    }
                    start++;
                }
                if (min_size > end - start + 1) {
                    min_size = end - start + 1;
                    start_ = start;
                    end_ = end + 1;
                }
            }
        }
        if (min_size < INT_MAX) {
            return S.substr(start_, end_ - start_);
        }
        return "";
    }
private:
    map<char, int> count_map_;
    int start_;
    int end_;
};
