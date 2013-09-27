class Solution {
public:
    string simplifyPath(string path) {
        deque<string> path_deque;
        int st = 0, ed;
        while (st < path.size()) {
            while (st < path.size() && path[st] == '/') {
                st++;
            }
            if (st >= path.size()) {
                break;
            }
            ed = st + 1;
            while (ed < path.size() && path[ed] != '/') {
                ed++;
            }
            string path_part = path.substr(st, ed - st);
            if (!path_part.empty()) {
                if (path_part == "..") {
                    if (!path_deque.empty()) {
                        path_deque.pop_back();
                    }
                } else if (path_part != ".") {
                    path_deque.push_back(path_part);
                }
            }
            st = ed + 1;
        }
        string res;
        while (!path_deque.empty()) {
            res.append("/");
            res.append(path_deque.front());
            path_deque.pop_front();
        }
        if (res.empty()) {
            res.append("/");
        }
        return res;
    }
};
