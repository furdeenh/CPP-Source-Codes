#include <iostream>
#include <vector>
#include <utility> // for swap()

using namespace std;

template <typename T>
int partition(vector<T>& vec, int low, int high)
{
    T pivot = vec[high];

    int i = low;
    int j = high - 1;

    while (true)
    {
        while (i < high && vec[i] < pivot)
        {
            ++i;
        }

        while (j >= low && vec[j] > pivot )
        {
            --j;
        }

        if( i >= j)
        {
            break;
        }

        swap(vec[i], vec[j]);
    }
    swap(vec[i], vec[high]);
    return i;  // return final index of the pivot;
}

template <typename T>
void quick_sort(vector<T>& vec, int low, int high)
{
    if (low >= high) return;

    int pivot_index = partition(vec, low, high);

    quick_sort(vec, low, pivot_index - 1);

    quick_sort(vec, pivot_index + 1, high);

}

template <typename T>
void print_vector(const vector<T>& vec)
{
    for (const auto v: vec)
    {
        cout << v << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> nums {7, 2, 1, 6, 8, 5, 3, 4};

    cout << "Unsorted Vector: ";
    print_vector(nums);
    
    cout << "Sorted Vector: ";
    quick_sort(nums, 0, nums.size() - 1);

    print_vector(nums);
    return 0;
}


