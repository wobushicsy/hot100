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
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode tmp{0, head};
    ListNode *p = &tmp;

    while (p->next != nullptr && p->next->next != nullptr) {
      auto pn = p->next;
      auto pnn = pn->next;
      pn->next = pnn->next;
      pnn->next = pn;
      p->next = pnn;
      p = p->next->next;
    }

    return tmp.next;
  }
};