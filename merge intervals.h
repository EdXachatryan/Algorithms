#pragma once

#include <vector>
#include <algorithm>
using std::vector;

/* 
	Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
	Output: [[1,6],[8,10],[15,18]]
	Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

vector<vector<int>> merge(vector<vector<int>>& intervals) {

	vector<vector<int>> mergedIntervals;
	std::sort(intervals.begin(), intervals.end());
	int firstBegin = intervals[0][0];
	int firstEnd = intervals[0][1];
	int joindPos = 0;
	mergedIntervals.push_back({ firstBegin, firstEnd });

	for (int pos = 1; pos < intervals.size(); ++pos) {
		int firstBegin = mergedIntervals[joindPos][0];
		int firstEnd = mergedIntervals[joindPos][1];
		
		int secondBegin = intervals[pos][0];
		int secondEnd = intervals[pos][1];
	
		if (firstEnd >= secondBegin) {

			int end = (secondEnd > firstEnd) ? secondEnd : firstEnd;
			mergedIntervals[joindPos][0] = firstBegin;
			mergedIntervals[joindPos][1] = end;
		}
		else {
			++joindPos;
			mergedIntervals.push_back({ secondBegin, secondEnd });
		}
	}
	
	return mergedIntervals;
}
