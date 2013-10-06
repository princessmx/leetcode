class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            string temp;
            char cur = res[0];
            int count = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] != cur) {
                    temp.push_back(count + '0');
                    temp.push_back(cur);
                    cur = res[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            temp.push_back(count + '0');
            temp.push_back(cur);
            swap(res, temp);
        }
        return res;
    }
};
