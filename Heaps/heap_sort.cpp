// Replace ___ with your code

#include <iostream>
#include <vector>
using namespace std;

class MinHeap {

private:
    vector<int> heap;

public:
    MinHeap() {}

    // Return the number of nodes in a heap
    int size() {
        return heap.size();
    }

    // Check if the heap is empty
    bool is_empty() {
        return heap.empty();
    }

    // String representation of a heap (for printing)
    string to_string() {
        string result = "[";
        for (int i = 0; i < heap.size(); i++) {
            result += std::to_string(heap[i]);
            if (i < heap.size() - 1) result += ", ";
        }
        result += "]";
        return result;
    }

    // Swap the heap values
    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
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

    // Heapify the array to build a min-heap
    void heapify(vector<int>& array) {
        heap = array;
        for (int i = heap.size() - 1; i >= 0; --i) {
            if (has_left_child(i)) {
                heapify_down(i);
            }
        }
    }

    // Heapify down
    void heapify_down(int index) {
        if (!has_left_child(index)) {
            return;
        }
        int smaller_child_index = left_child(index);
        if (has_right_child(index) && heap[right_child(index)] < heap[smaller_child_index]) {
            smaller_child_index = right_child(index);
        }
        if (heap[index] > heap[smaller_child_index]) {
            swap(index, smaller_child_index);
            if (has_left_child(smaller_child_index)) {
                heapify_down(smaller_child_index);
            }
        }
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
        heapify_up(size() - 1);
    }

    // Extract min from heap
    int extract_min() {
        int min = heap[0];
        if (size() == 1) {
            heap.clear();
            return min;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return min;
    }

    // Peek at the minimum value
    int peek() {
        return heap[0];
    }
};

vector<int> heap_sort(vector<int>& vec) {
    // Write your code here
    vector<int> sorted_vector;
    MinHeap heap;

    for (int v : vec)
    {
        heap.insert(v);
    }
    while (!heap.is_empty())
    {
        sorted_vector.push_back(heap.extract_min());
    }
    return sorted_vector;
}

int main() {
    vector<int> vec = {15, 12, 25, 16, 5};
    vector<int> sorted_vec = heap_sort(vec);

    for (int i : sorted_vec) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}