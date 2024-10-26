#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int> arr)
{
    int n = arr.size();
    int i = 0, d = 0;
    while (i < n)
    {
        if (i < n)
        {
            d = arr[i];
            i += d;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> v = {3, 5, 20, 1, 5, 9};
    cout << jump(v);
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<endl;
    // }
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i]<<endl;
    // }
    return 0;
}