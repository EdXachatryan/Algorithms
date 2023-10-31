#pragma once
#include <vector>

using std::vector;

/*
	Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
	Example 1:

	Input: nums = [1,2,3,4,5,6,7], k = 3
	Output: [5,6,7,1,2,3,4]


    [-1,-100,3,99]
    [3,99,-1,-100]
*/

void rotate(vector<int>& nums, int k) {

    if (k > nums.size())
        k = k % nums.size();

    int stepCount = 0;

    int lastValue = nums.at(0);
    int lastPos = 0;
    for (int i = 0; i < nums.size(); ++i) {

        lastPos = (lastPos + k >= nums.size()) ? (lastPos + k) - (nums.size()) : lastPos + k;
        int temp = nums[lastPos];
        nums[lastPos] = lastValue;
        lastValue = temp;
        stepCount++;
        if (nums.size() % 2 == 0 && stepCount * k > nums.size()) {
            ++lastPos;
            lastValue = nums[lastPos];
            stepCount = 0;
        }

            
    }
}
// todo unit test
