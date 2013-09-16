// Runtime: 60 ms
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int start_index = search(intervals, 0, intervals.size() - 1, newInterval.start);
        if (start_index == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int end_index = search(intervals, start_index + 1, intervals.size() - 1, newInterval.end);
        Strategy strategy = INSERT;
        if (start_index < 0) {
            if (end_index >= 0) {
                strategy = MERGE_TO_NEXT;
            }
        } else {
            if (start_index == end_index) {
                if (newInterval.start <= intervals[start_index].end && newInterval.end > intervals[start_index].end) {
                    strategy = MERGE_TO_START;
                } else if (newInterval.end <= intervals[start_index].end) {
                    return intervals;
                }
            } else {
                if (newInterval.start <= intervals[start_index].end) {
                    strategy = MERGE_TO_START;
                } else {
                    strategy = MERGE_TO_NEXT;
                }
            }
        }
        int del_count = 0, new_size;
        switch (strategy) {
            case INSERT:
                intervals.resize(intervals.size() + 1);
                for (int i = intervals.size() - 1; i > start_index + 1; i--) {
                    intervals[i] = intervals[i - 1];
                }
                intervals[start_index + 1] = newInterval;
                break;
            case MERGE_TO_START:
                intervals[start_index].end = max(intervals[end_index].end, newInterval.end);
                del_count = end_index - start_index;
                new_size = intervals.size() - del_count;
                for (int i = start_index + 1; i < new_size; i++) {
                    intervals[i] = intervals[i + del_count];
                }
                intervals.resize(new_size);
                break;
            case MERGE_TO_NEXT:
                intervals[start_index + 1].start = newInterval.start;
                intervals[start_index + 1].end = max(intervals[end_index].end, newInterval.end);
                del_count = end_index - start_index - 1;
                new_size = intervals.size() - del_count;
                for (int i = start_index + 2; i < new_size; i++) {
                    intervals[i] = intervals[i + del_count];
                }
                intervals.resize(new_size);
                break;
        }
        return intervals;
    }
private:
    int search(const vector<Interval> &intervals, int l, int r, int val) {
        int mid = l;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (intervals[mid].start > val) {
                r = mid - 1;
            } else if (intervals[mid].start < val) {
                l = mid + 1;
            } else {
                break;
            }
        }
        if (mid >= intervals.size() || intervals[mid].start > val) {
            mid--;
        }
        return mid;
    }
    enum Strategy {
        INSERT,
        MERGE_TO_START,
        MERGE_TO_NEXT,
    };
};
