// Replace ___ with your code

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinHeap {
public:
    vector<pair<int, string>> heap;

    MinHeap() {}

    int size()
    {
        return heap.size();
    }

    bool is_empty()
    {
        return heap.empty();
    }

    string to_string() {
        string result = "[";
        for (int i = 0; i < heap.size(); i++) {
            result += "(" + std::to_string(heap[i].first) + ", " + heap[i].second + ")";
            if (i < heap.size() - 1) result += ", ";
        }
        result += "]";
        return result;
    }

    void swap(int i, int j) {
        std::swap(heap[i], heap[j]);
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left_child(int index) {
        return 2 * index + 1;
    }

    int right_child(int index) {
        return 2 * index + 2;
    }

    bool has_parent(int index) {
        return parent(index) >= 0;
    }

    bool has_left_child(int index) {
        return left_child(index) < heap.size();
    }

    bool has_right_child(int index) {
        return right_child(index) < heap.size();
    }

    void heapify_down(int index) {
        if (!has_left_child(index)) return;
        int smaller_child_index = left_child(index);
        if (has_right_child(index) && heap[right_child(index)].first < heap[smaller_child_index].first) {
            smaller_child_index = right_child(index);
        }
        if (heap[index].first > heap[smaller_child_index].first) {
            swap(index, smaller_child_index);
            heapify_down(smaller_child_index);
        }
    }

    void heapify_up(int index) {
        if (has_parent(index)) {
            int parent_index = parent(index);
            if (heap[index].first < heap[parent_index].first) {
                    swap(index, parent_index);
                    heapify_up(parent_index);
            }
        }
    }

    void insert(pair<int, string> value) {
        heap.push_back(value);
        heapify_up(size() - 1);
    }

    pair<int, string> extract_min() {
        pair<int, string> min = heap[0];
        if (size() == 1) {
            heap.clear();
            return min;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return min;
    }

    pair<int, string> peek() {
        return heap[0];
    }
};

class PriorityQueue : public MinHeap {
public:
    PriorityQueue() : MinHeap() {}

    void insert(string value, int priority) {
        MinHeap::insert({priority, value});
    }

    pair<int, string> extract_min() {
        return MinHeap::extract_min();
    }

    pair<int, string> peek() {
        return MinHeap::peek();
    }

    void change_key(string value, int new_priority)
    {
        for (int i = 0; i < size(); i++)
        {
            if (heap[i].second == value)
            {
                int old_priority = heap[i].first;
                heap[i] = {new_priority, value};
                if (new_priority < old_priority)
                {
                    heapify_up(i);
                } else {
                    heapify_down(i);
                }
                return;
            }
        }
    }
};

int main()
{
    PriorityQueue priority_queue;

    vector<pair<int, string>> tasks = {{12, "Task1"}, {15, "Task2"}, {25, "Task3"}, {16, "Task4"}, {5, "Task5"}};

    cout << "Insert tasks into priority queue" << endl;
    
    for (auto& task : tasks)
    {
        priority_queue.insert(task.second, task.first);
    }
    cout << priority_queue.to_string() << endl;
    cout << "--------------" << endl;

    // Change the key of Task1 from 12 to 20
    cout << "Change priority of Task1 to 20" << endl;
    priority_queue.change_key("Task1", 20);
    cout << priority_queue.to_string() << endl;
    cout << "--------------" << endl;

    // Change the key of Task1 from 20 to 2
    cout << "Change priority of Task1 to 2" << endl;
    priority_queue.change_key("Task1", 2);
    cout << priority_queue.to_string() << endl;
    cout << "--------------" << endl;

    // Peek at the new element with the highest priority(min value)
    cout << "Top priority task" << endl;
    cout << "(" << priority_queue.peek().first << ", " << priority_queue.peek().second << ")" << endl;
    cout << "-----------" << endl;

    // Top priority task is complete
    priority_queue.extract_min();
    cout << "After removing top priority task" << endl;
    cout << priority_queue.to_string() << endl;

    return 0;


}

