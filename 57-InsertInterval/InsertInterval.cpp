#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
} Interval;

class Solution {
public:
	vector<Interval> insert(vector<Interval>&intervals, Interval newInterval) {
    	// quick sort with start element
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        sort(intervals, 0, intervals.size()-1);
        // if new interval is the smallest one
        if (newInterval.end < intervals[0].start) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        // if the new interval is the biggest one;
        if (newInterval.start > intervals[intervals.size()-1].end) {
            intervals.insert(intervals.begin()+intervals.size(), newInterval);
            return intervals;
        }
        int i = 0;
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            ++i;
        }
        if (newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].start) {
            int less = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start;
            int more = (intervals[i].end > newInterval.end) ? intervals[i].end : newInterval.end;
            int j = i+1;
            while (j < intervals.size() && intervals[j].start <= more) {
                more = (more > intervals[j].end) ? more : intervals[j].end;
                j++;
            }
            intervals.erase(intervals.begin()+i, intervals.begin()+j);
            intervals.insert(intervals.begin()+i, Interval(less, more));
        } else if (newInterval.end < intervals[i].start) {
            intervals.insert(intervals.begin()+i, newInterval);
        }
        return intervals;
	}

    void sort(vector<Interval>& intervals, int start, int end) {
        if (start < end) {
            int index = partition(intervals, start, end);
            sort(intervals, start, index-1);
            sort(intervals, index+1, end);
        }
    }

    int partition(vector<Interval>& intervals, int start, int end) {
        Interval middle = intervals[start];
        int lastLessIndex = end+1;
        int index = end;
        for ( ; index > start; --index) {
            if (intervals[index].start >= middle.start) {
                --lastLessIndex;
                if (lastLessIndex != index) swap(intervals[index], intervals[lastLessIndex]);
            }
        }
        swap(intervals[lastLessIndex-1], intervals[start]);
        return lastLessIndex-1;
    }

    void swap(Interval& i1, Interval& i2) {
        Interval temp = i1;
        i1 = i2;
        i2 = temp;
    }
};

int main() {
	Solution solution;
 	vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
    vector<Interval> result;
    result = solution.insert(intervals, Interval(4,9));
    for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << "," << result[i].end << "]  ";
	}
	cout << endl;
	return 0;
}
