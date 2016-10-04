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
		bool willCheck = true;
		while (willCheck) {
			
		}
		return result;
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
