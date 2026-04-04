#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<pair<int, int>> pr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pr.push_back({a, b});
    }
    cin >> m;
    string arrS[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arrS[i];
    }
    map<int, vector<string>> mpp;
    for (int i = 0; i < m; i++)
    {
        mpp[arrS[i].size()].push_back(arrS[i]);
    }
    
    for (int i = 0; i < m; i++)
    {
        // if(arrS[i].size() != n){
        //     cout << "No" << endl;
        //     break;
        // }
        int a = pr[i].first;
        for(int j = 0; j < m; j++){
          
        }
        
    }

    return 0;
}