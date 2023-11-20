#pragma once
#include <vector>
#include <map>

using std::vector;
using std::map;

vector<int> twoSum(vector<int>& nums, int target) {

	map<int, int> expectedNums;
	for (int pos = 0; pos < nums.size(); ++pos) {
		int num = nums[pos];

		if (expectedNums.find(num) != expectedNums.end()) {
			return { expectedNums.at(num), pos };
		}
		int number = target - num;

		expectedNums[number] = pos;
	}
	return {};
}