#pragma once

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {

	ListNode* newHead = nullptr;
	while ( head != nullptr) {
		ListNode* newNode = new ListNode(head->val);
		ListNode* temp = newHead;
		newNode->next = temp;
		newHead = newNode;
		head = head->next;
	}
	return newHead;
}


bool isPolindrome(ListNode* node) {

	ListNode* temp = node;
	ListNode* reversed = reverseList(temp);


	while (node != nullptr && reversed != nullptr) {

		if (node->val != reversed->val)
			return false;

		node = node->next;
		reversed = reversed->next;
	}
	return true;
}
