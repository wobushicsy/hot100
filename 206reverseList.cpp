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
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    return iterative(head);
  }

private:
  ListNode *iterative(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    ListNode *p = head;
    while (p->next != NULL) {
      p = p->next;
    }

    ListNode *tail = p;
    ListNode *pt = tail;
    p = head;
    while (p != tail) {
      auto tmp = p->next;
      p->next = pt->next;
      pt->next = p;
      p = tmp;
    }

    return tail;
  }
};