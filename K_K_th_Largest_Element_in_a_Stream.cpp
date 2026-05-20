#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/

class KthLargest
{
    vector<int> vec;

public:
    KthLargest(int k, vector<int> &nums)
    {

    }

    int add(int val)
    {
        vec.push_back(val);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    KthLargest obj(k, nums);

    int q;
    cin >> q;

    while (q--)
    {
        int val;
        cin >> val;

        cout << obj.add(val) << '\n';
    }

    return 0;
}