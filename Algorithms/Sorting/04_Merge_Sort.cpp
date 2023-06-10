//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* we recursively sort left and right array and then merge it together

//^ We're merging two sorted arrays that's why Merge Sort

//* Function for merging array from [left,mid] and [left,mid] and (mid,right]
void merge(vector<int> &nums, int left, int mid, int right)
{
    //* First we copy both part of array into two temp arrays
    int subArrOne = mid - left + 1;
    int subArrTwo = right - mid;
    vector<int> leftArr(subArrOne);
    vector<int> rightArr(subArrTwo);
    for (int i = 0; i < subArrOne; i++)
    {
        leftArr[i] = nums[left + i];
    }
    for (int i = 0; i < subArrTwo; i++)
    {
        rightArr[i] = nums[mid + 1 + i];
    }
    //* Now we start from beginning of both arrays and start updating original array
    int indLeft = 0, indRight = 0, indArr = left;
    while (indLeft < subArrOne && indRight < subArrTwo)
    {
        //* If first array contains smaller element then add it else vice-verse
        if (leftArr[indLeft] <= rightArr[indRight])
        {
            nums[indArr] = leftArr[indLeft++];
        }
        else
        {
            nums[indArr] = rightArr[indRight++];
        }
        indArr++;
    }

    //* Now one of the array will be empty and other one probably not, So add that

    //* If first one still has elements
    while (indLeft < subArrOne)
    {
        nums[indArr++] = leftArr[indLeft++];
    }
    //* If second one still has elements
    while (indRight < subArrTwo)
    {
        nums[indArr++] = rightArr[indRight++];
    }

    //* Free space to avoid memory leaks
    leftArr.clear();
    rightArr.clear();
}

//* Function to sort array from begin to all the way end
void mergeSort(vector<int> &nums, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    //* Find mid and divide array in two parts and sort both parts separately
    int mid = begin + (end - begin) / 2;
    mergeSort(nums, begin, mid);
    mergeSort(nums, mid + 1, end);
    //* After sorting, merge both array
    merge(nums, begin, mid, end);
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {10, 33, 3, 4, 24, 4, 5, 5, 7, 8, 9, 1, 5};

    mergeSort(nums, 0, nums.size() - 1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

//~ Time Complexity
//* Best Case: \omega (N * log N)
//* Average Case: \Theta (N * log N)
//* Worst Case: O(N * log N)

//~ Space Complexity:
//* O(N)