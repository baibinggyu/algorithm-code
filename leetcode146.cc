#include <list>
#include <unordered_map>
#include <utility>
class LRUCache {
private:
  size_t capacity_;
  std::list<std::pair<int, int>> cache_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash_;

public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    auto it = this->hash_.find(key);
    if (it == this->hash_.end())
      return -1;
    this->cache_.splice(this->cache_.begin(),this->cache_,it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = this->hash_.find(key);
    if (it == this->hash_.end()) {
      if (this->capacity_ == this->cache_.size()) {
        this->hash_.erase(this->cache_.back().first); 
        this->cache_.pop_back();
      }
      this->cache_.push_front(std::make_pair(key, value));
      this->hash_[key] = this->cache_.begin();
    } else {
      it->second->second = value;
      this->cache_.splice(this->cache_.begin(), this->cache_, it->second);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */