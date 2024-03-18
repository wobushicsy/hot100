#include <cstddef>

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
      val = _val;
      next = NULL;
      random = NULL;
  }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) {
      return NULL;
    }
    std::unordered_map<Node *, Node *> mapping;
    Node *h = new Node(head->val);
    Node *pn = h;
    Node *po = head;
    mapping[po] = pn;
    po = po->next;

    while (po != NULL) {
      pn->next = new Node(po->val);
      pn = pn->next;
      mapping[po] = pn;
      po = po->next;
    }

    pn->next = NULL;
    po = head;
    pn = h;
    while (po != NULL) {
      if (po->random == NULL) {
        mapping[po]->random = NULL;
      } else {
        mapping[po]->random = mapping[po->random];
      }
      po = po->next;
    }

    return h;
  }
};
