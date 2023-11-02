#pragma once

/*
	Input: l1 = [7,2,4,3], l2 = [5,6,4]
	Output: [7,8,0,7]
*/

/**
 * Definition for singly-linked list.
 * 
 */

#include <stack>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	std::stack<int> stackL1;
	std::stack<int> stackL2;

	while (l1 != nullptr) {
		stackL1.push(l1->val);
		l1 = l1->next;
	}
	while (l2 != nullptr) {
		stackL2.push(l2->val);
		l2 = l2->next;
	}
	
	std::stack<int> stackResult;
	int overflow = 0;
	while (!stackL1.empty() || !stackL2.empty()) {

		int num1 = 0;
		int num2 = 0;

		if (!stackL1.empty()) {
			num1 = stackL1.top();
			stackL1.pop();
		}

		if (!stackL2.empty()) {
			num2 = stackL2.top();
			stackL2.pop();
		}

		int sum = num1 + num2 + overflow;
		if (overflow >= 0)
			--overflow;

		if (sum > 10) {
			sum -= 10;
			++overflow;
		}

		stackResult.push(sum);
	}

	if (overflow)
		stackResult.push(overflow);

	ListNode* newHead = new ListNode();
	ListNode* temp = newHead;

	while (!stackResult.empty()) {
		temp->next = new ListNode(stackResult.top());
		stackResult.pop();
		temp = temp->next;
	}
	return newHead->next;
}