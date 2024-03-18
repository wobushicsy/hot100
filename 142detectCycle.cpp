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

#include <unordered_set>

const int MAX_LEN = 10001;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> nodes;
    ListNode *p = head;
    for (int i = 0; i < MAX_LEN; i++) {
      if (p == NULL) {
        break;
      }
      if (nodes.count(p) != 0) {
        return p;
      }
      nodes.insert(p);
      p = p->next;
    }

    return NULL;
  }
};