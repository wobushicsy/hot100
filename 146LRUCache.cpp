#include <unordered_map>

struct DLNode {
  DLNode(int key, int value) : key_(key), value_(value), prev_(nullptr), next_(nullptr) {}

  int key_;
  int value_;
  DLNode *prev_;
  DLNode *next_;
};

class LRUCache {
public:
  LRUCache(int capacity) : capacity_(capacity) {
    head_ = new DLNode(-1, -1);
    tail_ = new DLNode(-1, -1);
    head_->next_ = tail_;
    tail_->next_ = head_;
    size_ = 0;
  }

  ~LRUCache() {
    DLNode *p = head_->next_;
    while (p != tail_) {
      delete p->prev_;
      p = p->next_;
    }
    delete tail_;
  }

  int get(int key) {
    if (cache_.count(key) == 0) {
      return -1;
    }
    DLNode *node = cache_.at(key);
    moveToHead(node);
    return node->value_;
  }

  void put(int key, int value) {
    if (cache_.count(key) != 0) {
      DLNode *node = cache_.at(key);
      moveToHead(node);
      node->value_ = value;
      return;
    }

    if (size_ == capacity_) {
      DLNode *last = tail_->prev_;
      last->next_->prev_ = last->prev_;
      last->prev_->next_ = last->next_;
      cache_.erase(last->key_);
      delete last;
      size_--;
    }

    DLNode *n = new DLNode(key, value);
    n->next_ = head_->next_;
    n->prev_ = head_;
    n->next_->prev_ = n;
    n->prev_->next_ = n;
    cache_[key] = n;
    size_++;
  }

private:
  DLNode *head_;
  DLNode *tail_;
  int capacity_;
  int size_;
  std::unordered_map<int, DLNode *> cache_;

  void moveToHead(DLNode *node) {
    node->next_->prev_ = node->prev_;
    node->prev_->next_ = node->next_;
    node->next_ = head_->next_;
    node->prev_ = head_;
    node->next_->prev_ = node;
    node->prev_->next_ = node;
  }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */