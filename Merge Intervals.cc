/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), IntervalCmp());
        int last = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= intervals[last].end) {
                intervals[last].end = max(intervals[i].end, intervals[last].end);
            } else {
                last++;
                intervals[last] = intervals[i];
            }
        }
        if (!intervals.empty()) {
            intervals.resize(last + 1);
        }
        return intervals;
    }
private:
    struct IntervalCmp {
        bool operator() (const Interval &a, const Interval &b) const {
            return a.start < b.start;
        }
    };
};
