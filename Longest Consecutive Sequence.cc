// Small: 8ms; Large: 60ms
class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    map<int, int> num_map;
    for (int i = 0; i < num.size(); i++) {
      pair<map<int, int>::iterator, bool> res = num_map.insert(make_pair(num[i], num[i] + 1));
      if (!res.second) {
        continue;
      }
      map<int, int>::iterator it = res.first;
      bool should_leave = true;
      if (it != num_map.begin()) {
        it--;
        if (it->second >=num[i]) {
          should_leave = false;
          if (it->second == num[i]) {
            it->second = num[i] + 1;
          }
        }
      }
      map<int, int>::iterator post_it = res.first;
      post_it++;
      if (!should_leave) {
        num_map.erase(res.first);
      }
      it = post_it;
      it--;
      if (post_it != num_map.end() && post_it->first == it->second) {
        it->second = post_it->second;
        num_map.erase(post_it);
      }
    }
    int max_count = 0;
    for (map<int, int>::iterator it = num_map.begin();
         it != num_map.end();
         it++) {
      int count = it->second - it->first;
      if (max_count < count ) {
        max_count = count;
      }
    }
    return max_count;
  }
};
