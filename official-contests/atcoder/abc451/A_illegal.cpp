#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string str;
    cin >> str;
    if(str.length() == 5  or str.length() == 10){
        cout << "Yes";
    }else{
        cout << "No";
    }
    
    return 0;
}