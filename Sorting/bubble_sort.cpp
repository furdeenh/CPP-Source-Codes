// Replace ___ with your code

#include <iostream>
#include <vector>
 
using namespace std;

// Template to perform bubble sort on a vector

template<typename V>

// vector<int> nums = {1, 15, 6, 8, 2, 5, 9};

    // 1 = i = 0, j = 0, {1, 15, 6, 8, 2, 5, 9};   (j < 6)
    //     i = 0, j = 1, {1, 6, 15, 8, 2, 5, 9};
    //     i = 0, j = 2, {1, 6, 8, 15, 2, 5, 9};
    //     i = 0, j = 3, {1, 6, 8, 2, 15, 5, 9};
    //     i = 0, j = 4, {1, 6, 8, 2, 5, 15, 9};
    //     i = 0, j = 5, {1, 6, 8, 2, 5, 9, 15};


    // 2 = i = 1, j = 0, {1, 6, 8, 2, 5, 9, 15};   (j < 5)
    //     i = 1, j = 1, {1, 6, 8, 2, 5, 9, 15};
    //     i = 1, j = 2, {1, 6, 2, 8, 5, 9, 15};
    //     i = 1, j = 3, {1, 6, 2, 5, 8, 9, 15};
    //     i = 1, j = 4, {1, 6, 2, 5, 8, 9, 15};

    // 3 = i = 2, j = 0, {1, 6, 2, 5, 8, 9, 15};   (j < 4)
    //            j = 1, {1, 2, 6, 5, 8, 9, 15};
    //            j = 2, {1, 2, 5, 6, 8, 9, 15};


void bubble_sort(vector<V>& v)
{
     bool swapped = false; 
    for (int i = 0; i < v.size() - 1; i++)
    {

       swapped = false;

        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}


template<typename Z>

void print_vector(const vector<Z>& arr)
{
    for (const auto& a : arr )
    {
        cout << a << ' ';
    }
    cout << '\n';
}

 
int main() {
    // Initialize an unsorted vector and print it
    vector<int> nums {1, 15, 6, 8, 2, 5, 9}; 
    
    // Sort the vector using bubble sort and print it  
    bubble_sort(nums); 
    print_vector(nums); 
    return 0;
}