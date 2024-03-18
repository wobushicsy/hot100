#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

const int MAX_LEN = 10001;

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return false;
    }
    ListNode *fast = head->next;
    ListNode *slow = head;

    for (int i = 0; i < MAX_LEN; i++) {
      if (fast == slow) {
        return true;
      }
      if (fast == NULL || fast->next == NULL) {
        break;
      }
      fast = fast->next->next;
      slow = slow->next;
    }

    return false;
  }
};