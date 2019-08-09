#include "leetcode_solutions.h"

class LFUCache {
public:
 LFUCache(int capacity) {
  capacity_ = capacity;
  size_ = 0;
  min_frequency_ = 0;
 }

 int get(int key) {
  if (!cache_.count(key)) {
   return -1;
  }
  value_t value = cache_[key].first;
  frequency_t frequency = cache_[key].second++;
  list<key_t> & list = frequency_keys_map_[frequency];
  list.erase(pos_map_[key]);
  if (list.size() == 0) {
   frequency_keys_map_.erase(frequency_keys_map_.find(frequency));
   if (frequency == min_frequency_) min_frequency_++;
  }
  frequency_keys_map_[frequency + 1].push_front(key);
  pos_map_[key] = frequency_keys_map_[frequency + 1].begin();
  return value;
 }

 void put(int key, int value) {
  if (capacity_ == 0) return;
  if (get(key) != -1)
  {
   cache_[key].first = value;
   return;
  }
  if (size_ == capacity_) {
   list<key_t> & list = frequency_keys_map_[min_frequency_];
   auto it = prev(list.end());
   key_t key = *it;
   list.erase(it);
   cache_.erase(cache_.find(key));
   pos_map_.erase(pos_map_.find(key));
   size_--;
   if (list.size() == 0) {
    frequency_keys_map_.erase(frequency_keys_map_.find(min_frequency_));
   }
  }
  cache_.insert({ key,{value, 0} });
  frequency_keys_map_[0].push_front(key);
  pos_map_[key] = frequency_keys_map_[0].begin();
  size_++;
  min_frequency_ = 0;
 }
private:
 using frequency_t = int;
 using value_t = int;
 using key_t = int;
 int capacity_, size_;
 unordered_map<key_t, pair<value_t, frequency_t>> cache_;
 unordered_map<key_t, list<key_t>::iterator> pos_map_;
 unordered_map<frequency_t, list<key_t>> frequency_keys_map_;
 frequency_t min_frequency_;
};

int main() {
 
 LFUCache c(2);
 c.put(2,1);
 c.put(2, 2);
 c.get(2);
 c.put(1, 1);
 c.put(4, 1);
 c.get(2);
 return 0;
}