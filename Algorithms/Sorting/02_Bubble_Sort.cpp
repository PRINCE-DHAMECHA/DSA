//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Largest element will be bubbled and went straight to end and then we decrease our range and continue

//^ As largest element will be bubbles that's why bubble sort

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        //* No Element swapped means array is sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {10, 7, 8, 9, 1, 5};

    bubbleSort(nums);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

//~ Space Complexity:
//* Best Case: omega (N)
//* Average Case: Theta (N * log N)
//* Worst Case: O(N^2)

//~ Space Complexity:
//* Constant Memory O(1)