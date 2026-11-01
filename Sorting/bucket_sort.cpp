#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
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
        swap(vec[min_idx], vec[i]);
    }
}


template <typename T>
void bucket_sort(vector<T>& vec, const vector<pair<int, int>>& bucket_range) {
    vector<vector<T>> buckets(bucket_range.size());

    for (int i = 0; i < bucket_range.size(); ++i)
    {
        auto range = bucket_range[i];
        for (auto v : vec)
        {
            if (range.first <= v && v < range.second)
            {
                buckets[i].push_back(v);
            }
        }
    }

    vec.clear();
    for(auto& bucket : buckets)
    {
        selection_sort(bucket);
        vec.insert(vec.end(), bucket.begin(), bucket.end());
    }

    
}

int main() {

    vector<int> nums = {10, 8, 2, 1, 12, 7, 6, 14, 11, 4};
    vector<pair<int, int>> bucket_range = {{0, 5}, {5, 10}, {10, 15}};
    
    bucket_sort(nums, bucket_range);
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}