//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* There will be two array of one sorted and one unsorted and we select one element from unsorted and insert in sorted one
//* In beginning sorted array will be [0] and unsorted will be[1....n-1]
//* Now we choose {1} and insert in [0] so now [0 1] will be sorted as first two elements then select {2} and continue the process

//^ We're inserting element into sorted array that's why insertion sort

void insertionSort(vector<int> &nums)
{
    int n = nums.size(), key;
    for (int i = 1; i < n; i++)
    {
        key = nums[i];
        //* Start by comparing with i-1 i.e. last element of sorted array
        int j = i - 1;
        //* Shift larger values by one and place our key after encountering smaller element
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {10, 33, 3, 4, 24, 4, 5, 5, 7, 8, 9, 1, 5};

    insertionSort(nums);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

//~ Time Complexity:
//* Best Case: \omega (N)
//* Average Case: \Theta (N^2)
//* Worst Case: O(N^2)

//~ Space Complexity:
//* Constant Memory O(1)