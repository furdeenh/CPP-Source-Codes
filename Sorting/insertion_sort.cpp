// Replace ___ with your code

#include <iostream>
#include <vector>

using namespace std;

// Template to perform insertion sort on a vector.


//    vector<int> nums {1, 15, 6, 8, 2, 5, 9}; 

// i = 1, key = 15, {1, 15, 6, 8, 2, 5, 9}; 
// i = 2, key = 6,  {1, 15, 15, 8, 2, 5, 9};  & {1, 6, 15, 8, 2, 5, 9};  


template <typename T>
void insertion_sort(vector<T>& vec)
{
    for (int i = 1; i < vec.size(); ++i)
    {
        T key = vec[i];
        int j = i - 1;

        while (j>=0 && key < vec[j])
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}


// Template function to print elements of a vector.
template<typename T>
void print_vector(const vector<T>& arr) {
    for(const auto& elem: arr) {
        cout << elem << ' ';
    }
    cout << '\n'; 
}

int main() {
    // Initialize an unsorted vector and print it
    vector<int> nums {1, 15, 6, 8, 2, 5, 9}; 
    
    // Sort the vector using insertion sort.
    insertion_sort(nums); 
    
    // Print the sorted vector.
    print_vector(nums); 
    return 0;
}