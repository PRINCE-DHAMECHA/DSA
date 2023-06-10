//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//* We consider last element as pivot
int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high];
    //* Last index where smaller element inserted
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        //* If we find any element less than pivot then we add that after i
        if (nums[j] < pivot)
        {
            swap(nums[++i], nums[j]);
        }
    }
    //* at last we swap i+1 that will be larger than pivot or can be equals to pivot with pivot so pivot will be it's right position
    swap(nums[i + 1], nums[high]);
    //* Return index of pivot
    return i + 1;
}

void QS(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        //* fix position of pivot
        int pi = partition(nums, low, high);
        //* sort both sides
        QS(nums, low, pi - 1);
        QS(nums, pi + 1, high);
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {10, 7, 8, 9, 1, 5};

    QS(nums, 0, nums.size() - 1);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

//~ Time Complexity:
//* Best Case: \omega (N * log N)
//* Average Case: \Theta (N * log N)
//* Worst Case: O(N2)

//~ Space Complexity:
//* O(log N)