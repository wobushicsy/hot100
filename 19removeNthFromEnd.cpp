struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <unordered_map>

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    std::unordered_map<int, ListNode*> nodeId;
    ListNode *p = head;
    int idx = 0;
    while (p != nullptr) {
      nodeId[idx] = p;
      idx++;
      p = p->next;
    }

    if (n == idx) {
      auto ans = head->next;
      head->next = nullptr;
      head = ans;
    } else {
      idx = idx - n - 1;
      auto prev = nodeId[idx];
      prev->next = prev->next->next;
    }

    return head;
  }
};
