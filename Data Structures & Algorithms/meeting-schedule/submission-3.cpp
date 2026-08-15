/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
constexpr bool cmp(const Interval& i1, const Interval& i2) {
    return i1.start >= i2.start;
}

int partition(vector<Interval>& intervals, int low, int high) {
    int pivotIndex = high;
    int i = low - 1; 

    for(int j = low; j < high; ++j) {
        if (cmp(intervals[pivotIndex], intervals[j])) {
            i += 1;
            swap(intervals[i], intervals[j]);
        }
    }
    swap(intervals[high], intervals[i + 1]);
    return i + 1;
}

void quicksort(vector<Interval>& intervals, int low = 0, int high = -1) {
    if (-1 == high) {
        high = intervals.size() - 1;
    }

    if (low < high) {
        int pivot_index = partition(intervals, low, high);
        quicksort(intervals, low, pivot_index - 1);
        quicksort(intervals, pivot_index + 1, high);
    }
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), cmp);
        quicksort(intervals);
        for (int i = 0; i < intervals.size(); ++i) {
            cout << "(" << intervals[i].start << "," << intervals[i].end << ")" << endl;
        }
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
