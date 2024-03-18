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
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    int lenA = 0;
    while (pa != NULL) {
      pa = pa->next;
      lenA++;
    }

    ListNode *pb = headB;
    int lenB = 0;
    while (pb != NULL) {
      pb = pb->next;
      lenB++;
    }

    pa = headA;
    pb = headB;
    ListNode *&p = lenA > lenB ? pa : pb;
    int diff = lenA > lenB ? lenA - lenB : lenB - lenA;
    for (int i = 0; i < diff; i++) {
      p = p->next;
    }

    while (pa != NULL && pb != NULL) {
      if (pa == pb) {
        return pa;
      }
      pa = pa->next;
      pb = pb->next;
    }

    return 0;
  }
};