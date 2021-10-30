
#include "priorityqueue.h"

PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) {
	// adds a key with pair values to the end of the vector, then heapifies it up. 
    nodes_.push_back(kv);
    size_++;
    int i = size();
    heapifyUp(i);
}

KeyValuePair PriorityQueue::min() {
	//Returns the node with the lowest key value,
    return nodes_[ROOT];
}

KeyValuePair PriorityQueue::removeMin() {
	//Returns and removes the lowest (root) node
    KeyValuePair temp = min();
    removeNode(ROOT);
    return temp;
}

bool PriorityQueue::isEmpty() const {
    //Returns true iff the heap is empty
    return size() == 0;
}

size_t PriorityQueue::size() const {
    //returns the size of the KV pairs in the heap
    return size_;
}

nlohmann::json PriorityQueue::JSON() const {
	nlohmann::json result;
  for (size_t i = 1; i <= size_; i++) {
      nlohmann::json node;
      KeyValuePair kv = nodes_[i];
      node["key"] = kv.first;
      node["value"] = kv.second;
      if (i != ROOT) {
          node["parent"] = std::to_string(i / 2);
      }
      if (2 * i <= size_) {
          node["leftChild"] = std::to_string(2 * i);
      }
      if (2 * i + 1 <= size_) {
          node["rightChild"] = std::to_string(2 * i + 1);
      }
      result[std::to_string(i)] = node;
  }
  result["metadata"]["max_size"] = max_size_;
  result["metadata"]["size"] = size_;
	return result;
}

void PriorityQueue::heapifyUp(size_t i) {
	//checks if element has larger value than parent.
    if(i && nodes_[i/2] > nodes_[i]){
        swap(nodes_[i], nodes_[i/2]);
        heapifyUp(i/2);
    }
}

void PriorityQueue::heapifyDown(size_t i) {
    // Heapify Down function
    size_t left = (2 * i); //Finds left and right nodes
    size_t right = (2 * i + 1);
    size_t smallest = i;

    if (left <= size() && nodes_[left] < nodes_[i]){//if left is smaller, smallest is left
        smallest = left;
    }
    if (right <= size() && nodes_[right] < nodes_[smallest]){//if right is smaller, smallest is right
        smallest = right;
    }
    if (smallest != i){
        swap(nodes_[i], nodes_[smallest]);
        heapifyDown(smallest);//recurses until complete
    }
}

void PriorityQueue::removeNode(size_t i) {
	// removes node, decrements size of the queue, and heapifies the new 'root' node to its correct place
    nodes_[i] = nodes_.back();
    nodes_.pop_back();
    size_--;
    heapifyDown(ROOT);
}

Key PriorityQueue::getKey(size_t i) {
	//returns the key of the ith node
    return nodes_[i].first;
}
