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

#include <vector>
#include <algorithm>

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    std::vector<ListNode *> vec;
    while (head != nullptr) {
      vec.push_back(head);
      head = head->next;
    }

    std::sort(vec.begin(), vec.end(), [](ListNode *l, ListNode *r) -> bool {
      return l->val < r->val;
    });
    ListNode tmp;
    ListNode *p = &tmp;
    for (auto n : vec) {
      p->next = n;
      p = n;
    }
    p->next = nullptr;
    return tmp.next;
  }
};
