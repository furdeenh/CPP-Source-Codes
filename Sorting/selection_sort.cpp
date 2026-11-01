#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void selection_sort(vector<T>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        int min_idx = i;

        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[min_idx])
            {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
    }
}

template<typename T> 
void printv(const vector<T>& vec)
{
    for (const auto& v : vec)
    {
        cout << v << ' ';
    }
    cout << '\n';
}



int main() {
    
    // Initialize an unsorted vector and print it.
    vector<int> nums {1, 15, 6, 8, 2, 5, 9};
    
    // Sort the vector using selection sort and print it.   
    selection_sort(nums);
    printv(nums);
    return 0;
}