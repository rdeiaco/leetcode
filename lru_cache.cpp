#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Node {
public:
  Node(int key) : key(key), next(nullptr), prev(nullptr) {} 
  int key;
  Node *next;
  Node *prev;
};

class LRUCache {
public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    front = nullptr;
    back = nullptr;
  }

  int get(int key) {
    if (this->cache.find(key) == this->cache.end()) {
      // Key not found.
      return -1;
    }
    else {
      // Update priority.
      Node *update = priority[key];
      deleteAndReplaceNode(update, key);
      enqueue(key);
      return this->cache[key]; 
    }
    
  }

  void put(int key, int value) {
    if (this->cache.find(key) != this->cache.end()) {
      this->cache[key] = value;
      Node *update = priority[key];
      deleteAndReplaceNode(update, key);
      enqueue(key);
    }
    else if (size < capacity) {
      this->cache[key] = value;
      enqueue(key);
      size++;
    }
    else {
      // Evict the LRU element.
      int evict_key = front->key;
      deleteAndReplaceNode(this->front, key);
      this->cache.erase(evict_key);
      // Add new value with current priority.
      this->cache[key] = value;
      enqueue(key);
    }
  }

  void print_queue(void) {
    Node *temp = this->front;
    while (temp != nullptr) {
      cout << temp->key << " ";
      temp = temp->next;
    }
    cout << endl;
  }

private:
  void deleteAndReplaceNode(Node *to_delete, int key) {
    if (to_delete == this->front) {
      this->front = this->front->next;
      if (this->front == nullptr) {
        this->back = nullptr;
      }
    }
    if (to_delete == this->back) {
      this->back = this->back->prev;
      if (this->back == nullptr) {
        this->front = nullptr;
      }
    }

    if (to_delete->next != nullptr) {
      to_delete->next->prev = to_delete->prev;
    }
    if (to_delete->prev != nullptr) {
      to_delete->prev->next = to_delete->next;
    }
    this->priority.erase(key);
    // This isn't handled well by the Leetcode judge.
    //free(to_delete);
    //to_delete = nullptr;
  }

  void enqueue(int key) {
      Node *new_node = new Node(key);
      new_node->prev = this->back;
      if (this->back != nullptr) {
        this->back->next = new_node;
      }
      this->back = new_node;
      if (this->front == nullptr) {
        this->front = this->back;
      }
      this->priority[key] = new_node;
  }

  const int capacity;
  int size;
  unordered_map<int, int> cache;
  unordered_map<int, Node*> priority;
  Node *front, *back;
};

int main(void) {
  LRUCache cache(2);
  cache.put(2, 1);
  cache.print_queue();
  cache.put(3, 2);
  cache.print_queue();
  cout << "cache[" << 3 << "] = " << cache.get(3) << endl;
  cache.print_queue();
  cout << "cache[" << 2 << "] = " << cache.get(2) << endl;
  cache.print_queue();
  cache.put(4, 3);
  cache.print_queue();
  cout << "cache[" << 2 << "] = " << cache.get(2) << endl;
  cache.print_queue();
  cout << "cache[" << 3 << "] = " << cache.get(3) << endl;
  cache.print_queue();
  cout << "cache[" << 4 << "] = " << cache.get(4) << endl;
}
