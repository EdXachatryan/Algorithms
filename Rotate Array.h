#pragma once

#include <vector>
#include <algorithm>

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

    // [1, 2, 3, 4, 5, 6, 7]
    // [5, 6, 7, 1, 2, 3, 4]
    // st1 reverse full      =>  7 6 5 4 3 2 1
    // st2 reverse begin,k   =>  5 6 7 4 3 2 1
    // st3 reverse k,end     =>  5 4 7 1 2 3 4
    
    k = k % nums.size();
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse( nums.begin() + k, nums.end());

}
// todo unit test
