#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &arr, int i, int j, int eaten){
    if(eaten == 0 and i<=j) return 2;
    
    if(i >= j) return INT_MIN;
    
    // alice eats
    int ans1 = 1 + f(arr, i+1, j, eaten + arr[i]);
    
    // bob eats
    int ans2 = 1 + f(arr, i, j-1, eaten - arr[j]);
    
    //both eats
    int ans3 = 2 + f(arr, i+1, j-1, eaten + arr[i] - arr[j]);
    
    int ans = max({ans1, ans2, ans3});
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    // vector<int> prefix_alice;
    // vector<int> prefix_bob;
    
    // prefix_bob.push_back(arr[n-1]);
    // prefix_alice.push_back(arr[0]);
    
    // for(int i=1; i<n; i++){
    //     int x = prefix_alice[i-1] + arr[i];
    //     prefix_alice.push_back(x);
        
    //     int y = prefix_bob[i-1] + arr[n-i-1];
    //     prefix_bob.push_back(y);
    // }
    
    // int i= 0;
    // int j = n-1;
    // int ans = 0;
    // while(i<=j){
    //     if(prefix_alice[i] == prefix_bob[j]){
    //         ans = i + n-j;
    //         break;
    //     }
    //     i++;
    //     j--;
    // }
    
    // cout << ans << "\n";
    
    int ans =  f(arr, 1, n-2, 0 + arr[0] - arr[n-1]);
    if(ans < 0){
        cout << 0 << "\n";
    }else{
        cout << ans << "\n";
    }
    

}