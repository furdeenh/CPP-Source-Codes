#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    MinHeap() {}

    // Return the number of nodes in the heap
    int size() {
        return heap.size();
    }

    // Check if the heap is empty
    bool is_empty() {
        return heap.size() == 0;
    }

    // String representation of a heap
    string to_string() {
        string result = "[";
        for (size_t i = 0; i < heap.size(); ++i) {
            result += std::to_string(heap[i]);
            if (i != heap.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

    // Swap the heap values
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Calculate the index of a node's parent
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Calculate the index of a node's left child
    int left_child(int index) {
        return 2 * index + 1;
    }

    // Calculate the index of a node's right child
    int right_child(int index) {
        return 2 * index + 2;
    }

    // Check if a node at a given index has a parent
    bool has_parent(int index) {
        return parent(index) >= 0;
    }

    // Check if a node at a given index has a left child
    bool has_left_child(int index) {
        return left_child(index) < heap.size();
    }

    // Check if a node at a given index has a right child
    bool has_right_child(int index) {
        return right_child(index) < heap.size();
    }

    // Heapify up from a given index
    void heapify_up(int index)
    {
        if(has_parent(index))
        {
            int parent_index = parent(index);
            if (heap[index] < heap[parent_index])
            {
                swap(index, parent_index);
                heapify_up(parent_index);
            }
        }
    }

    // Insert into heap
    void insert(int value)
    {
        heap.push_back(value);
        heapify_up(size() - 1);
    }
    
};

int main() {
    MinHeap heap;

    // Insert elements to heap
    heap.insert(10);
    heap.insert(40);
    heap.insert(20);
    heap.insert(30);
    cout << heap.to_string() << endl;

    
    return 0;
}