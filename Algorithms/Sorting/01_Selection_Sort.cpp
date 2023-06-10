//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* We select index one by one and find element which belongs to that index

//^ We're selecting minimum element every time that's why selection sort

void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    //* Select index one by one
    for (int i = 0; i < n; i++)
    {
        //* start finding smaller element from that index
        int minInd = i;
        //* Iterate to end
        for (int j = i + 1; j < n; j++)
        {
            //* If we find element less than current position save it
            if (nums[j] < nums[minInd])
            {
                minInd = j;
            }
        }
        //* If we find smaller element than swap it and continue
        if (minInd != i)
        {
            swap(nums[minInd], nums[i]);
        }
    }
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {10, 7, 8, 9, 1, 5};

    selectionSort(nums);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

//~ Time Complexity:
//* O(N^2) (ALL)

//~ Space Complexity:
//* Constant Memory O(1)