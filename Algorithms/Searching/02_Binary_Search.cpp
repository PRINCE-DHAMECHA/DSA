//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* If given array is sorted then we can use binary search
//* We compare key with mid element and if it's less than mid then we know our key can be in left side but not at all at right side so we reduced high comparison at every comparison and vice-versa

int binarySearchRec(vector<int> &nums, int low, int high, int key)
{
    //* until low is less than or equal to high because high<low doesn't make any sense
    if (low <= high)
    {
        //* Find mid
        int mid = low + (high - low) / 2;
        //* Compare it with key
        if (nums[mid] == key)
        {
            return mid;
        }
        //* Key is in left side excluding mid
        if (nums[mid] > key)
        {
            return binarySearchRec(nums, low, mid - 1, key);
        }
        //* Key is in right side excluding mid
        else
        {
            return binarySearchRec(nums, mid + 1, high, key);
        }
    }
    //* Key not found
    return -1;
}

int binarySearch(vector<int> nums, int key)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == key)
        {
            return mid;
        }
        //* If key larger than mid then search in right side from mid+1 to high
        if (nums[mid] < key)
        {
            low = mid + 1;
        }
        //* Else search in left side till mid-1
        else
        {
            high = mid - 1;
        }
    }
    //* low>high but we still didn't find key then it'll be surely absent in given array
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {3, 43, 24, 2, 5, 34, 5, 35, 6, 456, 4, 7, 64, 7, 5, 4, 5, 54, 3};
    sort(nums.begin(), nums.end());
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    int ind1 = binarySearchRec(nums, 0, nums.size() - 1, 5);
    int ind2 = binarySearchRec(nums, 0, nums.size() - 1, 50);
    cout << ind1 << " " << ind2 << endl;
    int ind3 = binarySearch(nums, 5);
    int ind4 = binarySearch(nums, 50);
    cout << ind3 << " " << ind4 << endl;
    return 0;
}