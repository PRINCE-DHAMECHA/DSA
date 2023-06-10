//-----------------------//
//----PRINCE-DHAMECHA----//
//-----------------------//

#include <bits/stdc++.h>
using namespace std;
#define __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$ \
    ios::sync_with_stdio(0);                              \
    cin.tie(0)

//~ Approach:
//* Pretty much straight forward

int search(vector<int> &nums, int key)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    __DONT_RAISE_YOUR_VOICE__IMPROVE_YOUR_ARGUMENT__$;

    vector<int> nums = {3, 43, 24, 2, 5, 34, 5, 35, 6, 456, 4, 7, 64, 7, 5, 4, 5, 54, 3};
    int ind1 = search(nums, 5);
    int ind2 = search(nums, 50);
    cout << ind1 << " " << ind2 << endl;
    return 0;
}