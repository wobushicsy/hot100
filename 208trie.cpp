#include <string>
#include <memory>

const int MAX_SIZE = 26;

class TrieNode {
 public:
  TrieNode(bool is_end) {
    for (int i = 0; i < MAX_SIZE; i++) {
      nodes[i] = nullptr;
    }
    is_end_ = is_end;
  }

  std::shared_ptr<TrieNode> nodes[MAX_SIZE];
  bool is_end_;
};

class Trie {
public:
  Trie() {
    root_ = std::make_shared<TrieNode>(false);
  }
  
  void insert(std::string word) {
    int size = word.size();
    std::shared_ptr<TrieNode> p = root_;

    for (int i = 0; i < size; i++) {
      char c = word[i];
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) {
        p->nodes[idx] = std::make_shared<TrieNode>(false);
      }
      p = p->nodes[idx];
    }
    p->is_end_ = true;
  }
  
  bool search(std::string word) {
    int size = word.size();
    std::shared_ptr<TrieNode> p = root_;

    for (int i = 0; i < size; i++) {
      char c = word[i];
      int idx = c - 'a';
      
      if (p->nodes[idx] == nullptr) {
        return false;
      }
      p = p->nodes[idx];
    }

    return p->is_end_;
  }
  
  bool startsWith(std::string prefix) {
    int size = prefix.size();
    std::shared_ptr<TrieNode> p = root_;

    for (int i = 0; i < size; i++) {
      char c = prefix[i];
      int idx = c - 'a';
      
      if (p->nodes[idx] == nullptr) {
        return false;
      }
      p = p->nodes[idx];
    }

    return true;
  }

private:
  std::shared_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */