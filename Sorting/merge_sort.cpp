
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void merge(vector<T>& vec, int start_index, int middle_index, int end_index)
{
    vector<T> merged;
    int left = start_index;
    int right = middle_index;

    while (left < middle_index && right <= end_index)
    {
        if (vec[left] <= vec[right])
        {
            merged.push_back(vec[left]);
            ++left;
        } else {
            merged.push_back(vec[right]);
            ++right;
        }
    }

    while(left < middle_index)
    {
        merged.push_back(vec[left]);
        ++left;
    }
    while(right <= end_index)
    {
        merged.push_back(vec[right]);
        ++right;
    }

    for (int i = 0; i < merged.size(); ++i)
    {
        vec[start_index + i] = merged[i];
    }
}

template<typename T>
void merge_sort(vector<T>& vec, int start_index, int end_index) {
    
    if (start_index >= end_index) {
        return; 
    }

    int middle_index = start_index + (end_index - start_index + 1) / 2;
    
    merge_sort(vec, start_index, middle_index-1);
    
    merge_sort(vec, middle_index, end_index);
    
    merge(vec, start_index, middle_index, end_index);
}

template <typename T>
void print_vector(const vector<T>& vec)
{
    for (const auto& v : vec)
    {
        cout << v << ' ';
    }
    cout << endl;
}


int main() {
    // Initialize and print an unsorted vector
    vector<int> nums {6, 8, 1, 4, 5, 3, 7, 2}; 
    cout << "Unsorted Vector: ";
    print_vector(nums);
    
    // Sort the vector using merge sort.
    merge_sort(nums, 0, nums.size() - 1); 
    cout << "Sorted Vector: ";
    print_vector(nums); 
    return 0;
}


// #include <vector>
// #include <iostream>
// using namespace std;


// // vector<int> nums {1, 15, 6, 8, 2, 5, 9}; 

// // [1, 15, 6]    [8, 2, 5, 9]       mid = 8;




// template<typename V>
// void merge(vector<V>& vec, int start, int mid, int end)
// {
//     vector<V> merged;
//     int left = start;
//     int right = mid;

//     while(left < mid && right <= end)
//     {
//         if (vec[left] >= vec[right])
//         {
//             merged.push_back(vec[left]);
//             ++left;
//         } else {
//             merged.push_back(vec[right]);
//             ++right;
//         }
//     }

//     while (left < mid)
//     {
//        merged.push_back(vec[left]);
//        ++left;
//     }

//     while (right <= end )
//     {
//         merged.push_back(vec[right]);
//         ++right;
//     }

//     for (int i =0; i < merged.size(); i ++)
//     {
//         vec[start + i] = merged[i];
//     }

// }


// // Function to perform merge sort
// template<typename T>
// void merge_sort(vector<T>& arr, int start_index, int end_index) {
    
//     // If there are fewer than 2 elements, 
//     // return immediately.
//     if (start_index >= end_index) {
//         return; 
//     }

//     int middle_index = start_index + (end_index - start_index + 1) / 2;
    
//     // Recursively sort the left half of the vector.
//     merge_sort(arr, start_index, middle_index-1);
    
//     // Recursively sort the right half of the vector.
//     merge_sort(arr, middle_index, end_index);
    
//     // Merge the sorted halves.
//     merge(arr, start_index, middle_index, end_index);
// }

// // Function to print elements of a vector.
// template<typename T>
// void print_vector(const vector<T>& arr) {
    
//      // Iterate through the vector 
//     // and print each element followed by a space.
//     for (const auto& elem : arr) {
//         cout << elem << ' ';
//     }
//     cout << '\n';
// }

// int main() {
//     // Initialize an unsorted vector
//     vector<int> nums {1, 15, 6, 8, 2, 5, 9}; 

//     // Sort the vector using merge sort.
//     merge_sort(nums, 0, nums.size() - 1); 
//     print_vector(nums); 
//     return 0;
// }






// Initial Source Code
// #include <vector>
// #include <iostream>
// using namespace std;

// template <typename T>
// void print_vector(const vector<T>& vec, int start, int end)
// {
//     for (int i = start; i <= end; ++i)
//     {
//         cout << vec[i] << ' ';
//     }
//     cout << '\n';
// }

// template <typename T>
// void merge_sort(vector<T>& vec, int start_index, int end_index)
// {
//     if(start_index >= end_index)
//     {
//         return;
//     }

//     cout << "current subvector: ";

//     print_vector(vec, start_index, end_index);

//     int middle_index = start_index + (end_index - start_index + 1) / 2;
//     cout << "mid element = " << vec[middle_index];

//     cout << "left part: ";
//     print_vector(vec, start_index, middle_index - 1);
//     merge_sort(vec, start_index, middle_index - 1);

//     cout << "right part: ";
//     print_vector(vec, middle_index, end_index);
//     merge_sort(vec, middle_index, end_index);
// }

// int main()
// {
//     vector<int> data {5, 4, 7, 3, 2};
//     merge_sort(data, 0, data.size() - 1);
//     return 0;
// }