//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

int partition(vector<int> &nums, int low, int high)
{
    int pivot = nums[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void QS(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int pi = partition(nums, low, high);
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