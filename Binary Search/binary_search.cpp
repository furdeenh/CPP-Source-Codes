#include <iostream>
#include <vector>

using namespace std;

// Template to perform binary search on a sorted array.
template<typename V>
int binary_search(const vector<V>& vec, V target)
{
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low)/2;

        if (target == vec[mid])
        {
            return mid;
        }

        else if(target < vec[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
	// Initialize a vector of integers and specify the target value.
	vector<int> nums {4, 5, 9, 12, 55, 79, 88, 99};
	int target = 4;
	// Call binary_search function and capture the index result.
	int idx = binary_search(nums, target);
    
	// Output the result of the search.
	cout << idx << '\n';
	return 0;
}