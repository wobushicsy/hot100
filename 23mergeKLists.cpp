#include <vector>

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

#include <algorithm>

class Solution {
public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode tmp;
    ListNode *p = &tmp;

    std::vector<ListNode *>::iterator iter;
    while ((iter = std::find(lists.begin(), lists.end(), nullptr)) != lists.end()) {
      lists.erase(iter);
    }

    while (!lists.empty()) {
      int sz = lists.size();
      ListNode *n = lists.front();
      int idx = 0;
      for (int i = 1; i < sz; i++) {
        if (lists[i]->val < n->val) {
          n = lists[i];
          idx = i;
        }
      }
      p->next = n;
      p = n;
      lists[idx] = lists[idx]->next;

      std::vector<ListNode *>::iterator iter;
      while ((iter = std::find(lists.begin(), lists.end(), nullptr)) != lists.end()) {
        lists.erase(iter);
      }
    }

    p->next = nullptr;
    return tmp.next;
  }
};
