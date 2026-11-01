#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T>& vec, int interval) {
    for (int i = interval; i < vec.size(); i++) {
        T key = vec[i];
        int j = i - interval;
        while (j >= 0 && key < vec[j]) {
            vec[j + interval] = vec[j];
            j -= interval;
        }
        vec[j + interval] = key;
    }
}

template <typename T>
void shell_sort(vector<T>& vec) {
    int interval = vec.size() / 2;
    while (interval > 0) {
        insertion_sort(vec, interval);
        interval /= 2;
    }
}

// interval = 4;

int main() {

    vector<int> nums = {9, 8, 3, 7, 5, 6, 4, 1};
    int size = nums.size();

    // Function call
    shell_sort(nums);
    cout << "Sorted vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


/*

Descending order

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertion_sort(vector<T>& vec, int interval) {
    for (int i = interval; i < vec.size(); i++) {
        T key = vec[i];
        int j = i - interval;
        while (j >= 0 && key > vec[j]) {
            vec[j + interval] = vec[j];
            j -= interval;
        }
        vec[j + interval] = key;
    }
}

template <typename T>
void shell_sort(vector<T>& vec) {
    int interval = vec.size() / 2;
    while (interval > 0) {
        insertion_sort(vec, interval);
        interval /= 2;
    }
}


int main() {

    vector<int> nums = {1, 15, 6, 8, 2, 5, 9};
    int size = nums.size();

    // Function call
    shell_sort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}







*/