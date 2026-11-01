#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void counting_sort(vector<int>& nums, int place) {

    int size = nums.size();
    vector<int> output(size, 0);     // 7    place = 1
    vector<int> count(10, 0);     

    for (int i = 0; i < size; i++) {
        int index = nums[i] / place;        // {121, 432, 564, 23, 1, 45, 788}
        count[index % 10]++;              // 0 1 2 3 4 5 6 7 8 9
                                         // {0 2 1 1 1 1     1  }
    }

    for (int i = 1; i < 10; i++)
    {                                  // 0 1 2 3 4 5 6 7 8 9
        count[i] += count[i-1];       // {0 2 3 4 5 6 6 6 7 7 }
    }

    int i = size - 1;   // 6
    while (i >= 0)
    {
        int index = nums[i] / place;        // {121, 432, 564, 23, 1, 45, 788} 
        output[count[index%10] - 1] = nums[i];   // {121, 1, 432, 23, 564, 45, 788} 
        count[index % 10]--;                // {0 0 1 3 4 5 6 6 6 7}
        i--;    
    }

    for (int i = 0; i < size; i++)
    {
        nums[i] = output[i];
    }


}

void radix_sort(vector<int>& nums)        // {121, 1, 432, 23, 564, 45, 788} 
{
    int max = *max_element(nums.begin(), nums.end());    // 788
    int length = to_string(max).length();    // 3
    int place = 1;
    for (int i = 0; i < length; i++)
    {
        counting_sort(nums, place);
        place *= 10;
    }
}


int main() {

    vector<int> data = {121, 432, 564, 23, 1, 45, 788};
    cout << "Unsorted Data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    radix_sort(data);
    cout << "Sorted Data: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


/*
Descending Order:

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void counting_sort(vector<int>& nums, int place) {
    int size = nums.size();
    vector<int> output(size, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < size; i++) {
        int index = nums[i] / place;
        count[index % 10]++;
    }

    for (int i = 8; i >=0 ; i--) {
        count[i] += count[i + 1];
    }

    int i = size - 1;
    while (i >= 0) {
        int index = nums[i] / place;
        output[count[index % 10] - 1] = nums[i];
        count[index % 10]--;
        i--;
    }

    for (int i = 0; i < size; i++) {
        nums[i] = output[i];
    }
}

void radix_sort(vector<int>& nums) {
    int max_elem = *max_element(nums.begin(), nums.end());
    int length = to_string(max_elem).length();

    int place = 1;
    for (int i = 0; i < length; i++) {
        counting_sort(nums, place);
        place *= 10;
    }
}

int main() {

    vector<int> data = {1, 15, 6, 8, 2, 5, 9};

    radix_sort(data);
    for (int num : data) {
        cout << num << " ";
    }

    return 0;
}





*/