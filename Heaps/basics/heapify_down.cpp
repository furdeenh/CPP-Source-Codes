#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

public:
    MinHeap() {}

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

    // Swap the heap elements
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Calculate the index of a node's left child
    int left_child(int index) {
        return 2 * index + 1;
    }

    // Calculate the index of a node's right child
    int right_child(int index) {
        return 2 * index + 2;
    }

    // Check if a node at a given index has a left child
    bool has_left_child(int index) {
        return left_child(index) < heap.size();
    }

    // Check if a node at a given index has a right child
    bool has_right_child(int index) {
        return right_child(index) < heap.size();
    }

     // Calculate the index of a node's parent
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Check if a node at a given index has a parent
    bool has_parent(int index) {
        return parent(index) >= 0;
    }

    // Heapify up from a given index
    void heapify_up(int index) {
        if (has_parent(index)) {
            int parent_index = parent(index);
            if (heap[index] < heap[parent_index]) {
                swap(index, parent_index);
                heapify_up(parent_index);
            }
        }
    }


    // Insert into heap
    void insert(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    int extract_min() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapify_down(0);
        }
        return min;
    }

    // Heapify down from a given index
    void heapify_down(int index) {
        if (!has_left_child(index)) {
            return;
        }
        int smaller_child_index = left_child(index);
        if (has_right_child(index) && heap[right_child(index)] < heap[smaller_child_index]) {
            smaller_child_index = right_child(index);
        }
        if (heap[index] <= heap[smaller_child_index]) {
            return;
        }
        swap(index, smaller_child_index);
        heapify_down(smaller_child_index);
    }

    int peek() {
    return heap[0];
    }
};

int main() {

    MinHeap heap;
    vector<int> array_one = {5, 10, 15, 20, 25, 17};
    // Create an heap out an vector
    for(const int i: array_one){
        heap.insert(i);
    }
    
    cout << "Heap before extraction: " << heap.to_string() << endl;
    
    // Remove the smallest element and heapify
    heap.extract_min();
    cout << "Heap after extraction: " << heap.to_string() << endl;
    
    return 0;
}