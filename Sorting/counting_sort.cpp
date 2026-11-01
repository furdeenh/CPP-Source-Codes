#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//  vector<int> nums {5, 8, 4, 9, 7, 10, 3, 5, 4, 9}; 

vector<int> count_sort(const vector<int>& nums) {
    int max = *max_element(nums.begin(), nums.end());

    vector<int> counting_vector(max + 1, 0);    // max = 10

    for (const int n : nums)     // counting_vector[5] = counting_vector[5] + 1....
    {
        ++counting_vector[n];    
                                //          { 0, 0, 0, 1, 2, 2, 0, 0, 1, 9, 1 }
    }                           // index[n] [ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]                  


    vector<int> res_vector;
    
    for (int i = 0; i <= max; ++i)                      // i = 0, 1, 2, i = 3; j = 0 < 1 , j = 1
    {                                                  // j = 1 < 1 !!;  i = 4, j = 0 < 2, j = 1 < 2, j = 2 < 2 !! 
        for (int j = 0; j < counting_vector[i]; ++j)   // res_vector = {3, 4, 4}
        {
            res_vector.push_back(i);                             
        }
    }

    return res_vector;

}

template<typename T>
void print_vector(const vector<T>& arr) {
    
     // Iterate through the vector 
    // and print each element followed by a space.
    for (const auto& a : arr)
    {
        cout << a << ' ';
    }
    cout << '\n';
}


int main() {
    // Initialize an unsorted vector
    vector<int> nums {5, 8, 4, 9, 7, 10, 3, 5, 4, 9}; 
    
    // Sort the vector using counting sort
    vector<int> sorted_nums = count_sort(nums); 
    print_vector(sorted_nums);
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Function to perform counting sort on a vector
vector<int> count_sort(const vector<int>& nums) {
    int max = *max_element(nums.begin(), nums.end());
    vector<int> counting_vector(max+1, 0);

    for (const int i : nums)
    {
        ++counting_vector[i];  
    }

    vector<int> res_vector;
    for (int i = 0; i <= max; ++i)
    {
        for (int j = 0; j < counting_vector[i]; ++j)
        {
            res_vector.push_back(i);
        }
    }
    return res_vector;

}

int main() {
    // Initialize an unsorted vector
    vector<int> nums {5, 8, 4, 9, 7, 10, 3, 5, 4, 9}; 
    
    cout << "Unsorted Vector: ";
    print_vector(nums);
    // Sort the vector using counting sort
    vector<int> sorted_nums = count_sort(nums);
    cout << "Sorted Vector: "; 
    print_vector(sorted_nums);
    cout << endl;
    print_vector(counting_vector);
    return 0;
}













*/