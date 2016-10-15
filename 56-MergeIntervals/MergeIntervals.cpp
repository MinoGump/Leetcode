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
	vector<Interval> merge(vector<Interval>&intervals) {
		vector<Interval> result;
    	// quick sort with start element
        sort(intervals, 0, intervals.size()-1);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= intervals[i-1].end) {
                int less = intervals[i-1].start, more = (intervals[i].end > intervals[i-1].end) ? intervals[i].end : intervals[i-1].end;
                cout <<  i << "  " << less <<"  " << more << endl;
                intervals.erase(intervals.begin()+i-1, intervals.begin()+i+1);
                intervals.insert(intervals.begin()+i-1, Interval(less, more));
                --i;
            }
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
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));
    vector<Interval> result;
    result = solution.merge(intervals);
    for (int i = 0; i < result.size(); i++) {
		cout << "[" << result[i].start << "," << result[i].end << "]  ";
	}
	cout << endl;
	return 0;
}
