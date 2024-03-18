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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1) {
      return head;
    }
    ListNode tmp{0, head};
    ListNode *p = &tmp;

    while (p != nullptr) {
      ListNode *tail = p;
      for (int i = 0; i < k; i++) {
        if (tail == nullptr) {
          break;
        }
        tail = tail->next;
      }

      if (tail == nullptr) {
        break;
      }

      ListNode *next = tail->next;
      ListNode *prev = p;
      p = p->next;
      ListNode *head = p;
      while (p != tail) {
        auto tmp = p->next;
        p->next = tail->next;
        tail->next = p;
        p = tmp;
      }
      prev->next = tail;
      p = head;
    }

    return tmp.next;
  }
};
