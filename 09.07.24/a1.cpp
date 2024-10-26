// Given a sorted integer array arr, two integers k and x, return the k closest
// integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarysearch(vector<int> &arr, int target)
{
    int s = 0, e = arr.size() - 1, ans = e;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    if (arr.size() == 1 && k == 0)
    {
        return arr[0];
    }
    int pos = binarysearch(arr, x);
    int high = pos;
    int low = high - 1;

    while ((high - low) >= k)
    {
        if(abs(arr[low] - x)<=abs(arr[high]-x))
        {
            high--;
        }
        else{
            low++;
        }
    }
    return vector<int>(arr.begin()+low,arr.begin())
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> res = findClosestElements(arr, k, x);
    for (auto it:res)
    {
        cout << res[it];
    }
        ;
    return 0;
}