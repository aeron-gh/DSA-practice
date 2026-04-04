#include <bits/stdc++.h>
using namespace std;

const pair<int, int> a = {1, 7};
const pair<int, int> b = {3, 3};
const pair<int, int> c = {5, 5};
const pair<int, int> d = {7, 7};
const pair<int, int> e = {9, 9};

bool fes(pair<int, int> pr)
{
    if (pr == a || pr == b || pr == c || pr == d || pr == e)
    {
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int, int> pr;
    cin >> pr.first >> pr.second;
    if (fes(pr))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}