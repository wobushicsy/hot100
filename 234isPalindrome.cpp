#include <cstddef>

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

#include <deque>

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    std::deque<int> list;
    ListNode *p = head;
    
    while (p != NULL) {
      list.push_back(p->val);
      p = p->next;
    }

    while (!list.empty()) {
      if (list.front() != list.back()) {
        return false;
      }
      if (list.size() >= 2) {
        list.pop_back();
        list.pop_front();
      } else {
        list.pop_back();
      }
    }

    return true;
  }
};